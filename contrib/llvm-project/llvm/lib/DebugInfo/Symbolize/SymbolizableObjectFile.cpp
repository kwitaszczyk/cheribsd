//===- SymbolizableObjectFile.cpp -----------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// Implementation of SymbolizableObjectFile class.
//
//===----------------------------------------------------------------------===//

#include "SymbolizableObjectFile.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/Triple.h"
#include "llvm/BinaryFormat/COFF.h"
#include "llvm/DebugInfo/DWARF/DWARFContext.h"
#include "llvm/DebugInfo/Symbolize/SymbolizableModule.h"
#include "llvm/Object/COFF.h"
#include "llvm/Object/ObjectFile.h"
#include "llvm/Object/SymbolSize.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/DataExtractor.h"
#include "llvm/Support/Error.h"
#include <algorithm>
#include <cstdint>
#include <memory>
#include <string>
#include <system_error>
#include <utility>
#include <vector>

using namespace llvm;
using namespace object;
using namespace symbolize;

Expected<std::unique_ptr<SymbolizableObjectFile>>
SymbolizableObjectFile::create(const object::ObjectFile *Obj,
                               std::unique_ptr<DIContext> DICtx,
                               bool UntagAddresses) {
  assert(DICtx);
  std::unique_ptr<SymbolizableObjectFile> res(
      new SymbolizableObjectFile(Obj, std::move(DICtx), UntagAddresses));
  std::unique_ptr<DataExtractor> OpdExtractor;
  uint64_t OpdAddress = 0;
  // Find the .opd (function descriptor) section if any, for big-endian
  // PowerPC64 ELF.
  if (Obj->getArch() == Triple::ppc64) {
    for (section_iterator Section : Obj->sections()) {
      Expected<StringRef> NameOrErr = Section->getName();
      if (!NameOrErr)
        return NameOrErr.takeError();

      if (*NameOrErr == ".opd") {
        Expected<StringRef> E = Section->getContents();
        if (!E)
          return E.takeError();
        OpdExtractor.reset(new DataExtractor(*E, Obj->isLittleEndian(),
                                             Obj->getBytesInAddress()));
        OpdAddress = Section->getAddress();
        break;
      }
    }
  }
  std::vector<std::pair<SymbolRef, uint64_t>> Symbols =
      computeSymbolSizes(*Obj);
  for (auto &P : Symbols)
    if (Error E =
            res->addSymbol(P.first, P.second, OpdExtractor.get(), OpdAddress))
      return std::move(E);

  // If this is a COFF object and we didn't find any symbols, try the export
  // table.
  if (Symbols.empty()) {
    if (auto *CoffObj = dyn_cast<COFFObjectFile>(Obj))
      if (Error E = res->addCoffExportSymbols(CoffObj))
        return std::move(E);
  }

  std::vector<std::pair<SymbolDesc, StringRef>> &Fs = res->Functions,
                                                &Os = res->Objects;
  auto Uniquify = [](std::vector<std::pair<SymbolDesc, StringRef>> &S) {
    // Sort by (Addr,Size,Name). If several SymbolDescs share the same Addr,
    // pick the one with the largest Size. This helps us avoid symbols with no
    // size information (Size=0).
    llvm::sort(S);
    auto I = S.begin(), E = S.end(), J = S.begin();
    while (I != E) {
      auto OI = I;
      while (++I != E && OI->first.Addr == I->first.Addr) {
      }
      *J++ = I[-1];
    }
    S.erase(J, S.end());
  };
  Uniquify(Fs);
  Uniquify(Os);

  return std::move(res);
}

SymbolizableObjectFile::SymbolizableObjectFile(const ObjectFile *Obj,
                                               std::unique_ptr<DIContext> DICtx,
                                               bool UntagAddresses)
    : Module(Obj), DebugInfoContext(std::move(DICtx)),
      UntagAddresses(UntagAddresses) {}

namespace {

struct OffsetNamePair {
  uint32_t Offset;
  StringRef Name;

  bool operator<(const OffsetNamePair &R) const {
    return Offset < R.Offset;
  }
};

} // end anonymous namespace

Error SymbolizableObjectFile::addCoffExportSymbols(
    const COFFObjectFile *CoffObj) {
  // Get all export names and offsets.
  std::vector<OffsetNamePair> ExportSyms;
  for (const ExportDirectoryEntryRef &Ref : CoffObj->export_directories()) {
    StringRef Name;
    uint32_t Offset;
    if (auto EC = Ref.getSymbolName(Name))
      return EC;
    if (auto EC = Ref.getExportRVA(Offset))
      return EC;
    ExportSyms.push_back(OffsetNamePair{Offset, Name});
  }
  if (ExportSyms.empty())
    return Error::success();

  // Sort by ascending offset.
  array_pod_sort(ExportSyms.begin(), ExportSyms.end());

  // Approximate the symbol sizes by assuming they run to the next symbol.
  // FIXME: This assumes all exports are functions.
  uint64_t ImageBase = CoffObj->getImageBase();
  for (auto I = ExportSyms.begin(), E = ExportSyms.end(); I != E; ++I) {
    OffsetNamePair &Export = *I;
    // FIXME: The last export has a one byte size now.
    uint32_t NextOffset = I != E ? I->Offset : Export.Offset + 1;
    uint64_t SymbolStart = ImageBase + Export.Offset;
    uint64_t SymbolSize = NextOffset - Export.Offset;
    SymbolDesc SD = {SymbolStart, SymbolSize};
    Functions.emplace_back(SD, Export.Name);
  }
  return Error::success();
}

Error SymbolizableObjectFile::addSymbol(const SymbolRef &Symbol,
                                        uint64_t SymbolSize,
                                        DataExtractor *OpdExtractor,
                                        uint64_t OpdAddress) {
  // Avoid adding symbols from an unknown/undefined section.
  const ObjectFile *Obj = Symbol.getObject();
  Expected<section_iterator> Sec = Symbol.getSection();
  if (!Sec || (Obj && Obj->section_end() == *Sec))
    return Error::success();
  Expected<SymbolRef::Type> SymbolTypeOrErr = Symbol.getType();
  if (!SymbolTypeOrErr)
    return SymbolTypeOrErr.takeError();
  SymbolRef::Type SymbolType = *SymbolTypeOrErr;
  if (SymbolType != SymbolRef::ST_Function && SymbolType != SymbolRef::ST_Data)
    return Error::success();
  Expected<uint64_t> SymbolAddressOrErr = Symbol.getAddress();
  if (!SymbolAddressOrErr)
    return SymbolAddressOrErr.takeError();
  uint64_t SymbolAddress = *SymbolAddressOrErr;
  if (UntagAddresses) {
    // For kernel addresses, bits 56-63 need to be set, so we sign extend bit 55
    // into bits 56-63 instead of masking them out.
    SymbolAddress &= (1ull << 56) - 1;
    SymbolAddress = (int64_t(SymbolAddress) << 8) >> 8;
  }
  if (OpdExtractor) {
    // For big-endian PowerPC64 ELF, symbols in the .opd section refer to
    // function descriptors. The first word of the descriptor is a pointer to
    // the function's code.
    // For the purposes of symbolization, pretend the symbol's address is that
    // of the function's code, not the descriptor.
    uint64_t OpdOffset = SymbolAddress - OpdAddress;
    if (OpdExtractor->isValidOffsetForAddress(OpdOffset))
      SymbolAddress = OpdExtractor->getAddress(&OpdOffset);
  }
  Expected<StringRef> SymbolNameOrErr = Symbol.getName();
  if (!SymbolNameOrErr)
    return SymbolNameOrErr.takeError();
  StringRef SymbolName = *SymbolNameOrErr;
  // Mach-O symbol table names have leading underscore, skip it.
  if (Module->isMachO() && !SymbolName.empty() && SymbolName[0] == '_')
    SymbolName = SymbolName.drop_front();
  // FIXME: If a function has alias, there are two entries in symbol table
  // with same address size. Make sure we choose the correct one.
  auto &M = SymbolType == SymbolRef::ST_Function ? Functions : Objects;
  SymbolDesc SD = { SymbolAddress, SymbolSize };
  M.emplace_back(SD, SymbolName);
  return Error::success();
}

// Return true if this is a 32-bit x86 PE COFF module.
bool SymbolizableObjectFile::isWin32Module() const {
  auto *CoffObject = dyn_cast<COFFObjectFile>(Module);
  return CoffObject && CoffObject->getMachine() == COFF::IMAGE_FILE_MACHINE_I386;
}

uint64_t SymbolizableObjectFile::getModulePreferredBase() const {
  if (auto *CoffObject = dyn_cast<COFFObjectFile>(Module))
    return CoffObject->getImageBase();
  return 0;
}

bool SymbolizableObjectFile::getNameFromSymbolTable(SymbolRef::Type Type,
                                                    uint64_t Address,
                                                    std::string &Name,
                                                    uint64_t &Addr,
                                                    uint64_t &Size) const {
  const auto &Symbols = Type == SymbolRef::ST_Function ? Functions : Objects;
  std::pair<SymbolDesc, StringRef> SD{{Address, UINT64_C(-1)}, StringRef()};
  auto SymbolIterator = llvm::upper_bound(Symbols, SD);
  if (SymbolIterator == Symbols.begin())
    return false;
  --SymbolIterator;
  if (SymbolIterator->first.Size != 0 &&
      SymbolIterator->first.Addr + SymbolIterator->first.Size <= Address)
    return false;
  Name = SymbolIterator->second.str();
  Addr = SymbolIterator->first.Addr;
  Size = SymbolIterator->first.Size;
  return true;
}

bool SymbolizableObjectFile::shouldOverrideWithSymbolTable(
    FunctionNameKind FNKind, bool UseSymbolTable) const {
  // When DWARF is used with -gline-tables-only / -gmlt, the symbol table gives
  // better answers for linkage names than the DIContext. Otherwise, we are
  // probably using PEs and PDBs, and we shouldn't do the override. PE files
  // generally only contain the names of exported symbols.
  return FNKind == FunctionNameKind::LinkageName && UseSymbolTable &&
         isa<DWARFContext>(DebugInfoContext.get());
}

DILineInfo
SymbolizableObjectFile::symbolizeCode(object::SectionedAddress ModuleOffset,
                                      DILineInfoSpecifier LineInfoSpecifier,
                                      bool UseSymbolTable) const {
  if (ModuleOffset.SectionIndex == object::SectionedAddress::UndefSection)
    ModuleOffset.SectionIndex =
        getModuleSectionIndexForAddress(ModuleOffset.Address);
  DILineInfo LineInfo =
      DebugInfoContext->getLineInfoForAddress(ModuleOffset, LineInfoSpecifier);

  // Override function name from symbol table if necessary.
  if (shouldOverrideWithSymbolTable(LineInfoSpecifier.FNKind, UseSymbolTable)) {
    std::string FunctionName;
    uint64_t Start, Size;
    if (getNameFromSymbolTable(SymbolRef::ST_Function, ModuleOffset.Address,
                               FunctionName, Start, Size)) {
      LineInfo.FunctionName = FunctionName;
    }
  }
  return LineInfo;
}

DIInliningInfo SymbolizableObjectFile::symbolizeInlinedCode(
    object::SectionedAddress ModuleOffset,
    DILineInfoSpecifier LineInfoSpecifier, bool UseSymbolTable) const {
  if (ModuleOffset.SectionIndex == object::SectionedAddress::UndefSection)
    ModuleOffset.SectionIndex =
        getModuleSectionIndexForAddress(ModuleOffset.Address);
  DIInliningInfo InlinedContext = DebugInfoContext->getInliningInfoForAddress(
      ModuleOffset, LineInfoSpecifier);

  // Make sure there is at least one frame in context.
  if (InlinedContext.getNumberOfFrames() == 0)
    InlinedContext.addFrame(DILineInfo());

  // Override the function name in lower frame with name from symbol table.
  if (shouldOverrideWithSymbolTable(LineInfoSpecifier.FNKind, UseSymbolTable)) {
    std::string FunctionName;
    uint64_t Start, Size;
    if (getNameFromSymbolTable(SymbolRef::ST_Function, ModuleOffset.Address,
                               FunctionName, Start, Size)) {
      InlinedContext.getMutableFrame(InlinedContext.getNumberOfFrames() - 1)
          ->FunctionName = FunctionName;
    }
  }

  return InlinedContext;
}

DIGlobal SymbolizableObjectFile::symbolizeData(
    object::SectionedAddress ModuleOffset) const {
  DIGlobal Res;
  getNameFromSymbolTable(SymbolRef::ST_Data, ModuleOffset.Address, Res.Name,
                         Res.Start, Res.Size);
  return Res;
}

std::vector<DILocal> SymbolizableObjectFile::symbolizeFrame(
    object::SectionedAddress ModuleOffset) const {
  if (ModuleOffset.SectionIndex == object::SectionedAddress::UndefSection)
    ModuleOffset.SectionIndex =
        getModuleSectionIndexForAddress(ModuleOffset.Address);
  return DebugInfoContext->getLocalsForAddress(ModuleOffset);
}

/// Search for the first occurence of specified Address in ObjectFile.
uint64_t SymbolizableObjectFile::getModuleSectionIndexForAddress(
    uint64_t Address) const {

  for (SectionRef Sec : Module->sections()) {
    if (!Sec.isText() || Sec.isVirtual())
      continue;

    if (Address >= Sec.getAddress() &&
        Address < Sec.getAddress() + Sec.getSize())
      return Sec.getIndex();
  }

  return object::SectionedAddress::UndefSection;
}
