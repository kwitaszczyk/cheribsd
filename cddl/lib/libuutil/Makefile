# $FreeBSD$

.PATH: ${SRCTOP}/sys/contrib/openzfs/lib/libuutil

PACKAGE=	runtime
LIB=	uutil
SRCS=\
	uu_alloc.c \
	uu_avl.c \
	uu_dprintf.c \
	uu_ident.c \
	uu_list.c \
	uu_misc.c \
	uu_open.c \
	uu_pname.c \
	uu_string.c

WARNS?=	2
CFLAGS+= -DIN_BASE
CFLAGS+= -I${SRCTOP}/sys/contrib/openzfs/include
CFLAGS+= -I${SRCTOP}/sys/contrib/openzfs/lib/libspl/include/
CFLAGS+= -I${SRCTOP}/sys/contrib/openzfs/lib/libspl/include/os/freebsd
CFLAGS+= -I${SRCTOP}/sys
CFLAGS+= -I${SRCTOP}/cddl/compat/opensolaris/include
CFLAGS+= -include ${SRCTOP}/sys/contrib/openzfs/include/os/freebsd/spl/sys/ccompile.h

LIBADD= avl spl

# The aok vairable used by assert() is defined in
# sys/cddl/contrib/opensolaris/common/nvpair/opensolaris_nvpair.c so we need
# to link against nvpair in order to get size information for that file
# (at least for libcheri)
LIBADD+=	nvpair

.include <bsd.lib.mk>
