# $FreeBSD$

.include <src.opts.mk>

PACKAGE= tests

TESTSDIR= ${TESTSBASE}

${PACKAGE}FILES+=		README

KYUAFILE= yes

SUBDIR.${MK_COMPAT_CHERIABI}+=	cheri
SUBDIR+= etc
SUBDIR+= sys

SUBDIR_PARALLEL=

afterinstall: install-tests-local
install-tests-local: .PHONY
	${INSTALL_SYMLINK} -T 'package=tests' \
	    ../local/tests ${DESTDIR}${TESTSDIR}/local

.include "Makefile.inc0"
.include <bsd.test.mk>
