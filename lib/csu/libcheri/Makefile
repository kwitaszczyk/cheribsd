# $FreeBSD$

.include <src.opts.mk>

.if !${MACHINE_ABI:Mpurecap}
NEED_COMPAT=	CHERI
.include <bsd.compat.mk>
.endif

.PATH: ${.CURDIR}/../common-cheri
CFLAGS+=	-I${.CURDIR}/../common		\
		-I${.CURDIR}/../common-cheri
SRCS=	crt_invoke.S				\
	crt_rtld.S				\
	Ccrt1.c					\
	crtbeginC.c				\
	crtendC.c
FILES=	${SRCS:C/.[cS]$/.o/}

FILESOWN=       ${LIBOWN}
FILESGRP=       ${LIBGRP}
FILESMODE=      ${LIBMODE}
FILESDIR=       ${LIBDIR}
# These FILES qualify as libraries for the purpose of LIBRARIES_ONLY.
.undef LIBRARIES_ONLY
CLEANFILES=	${FILES}
CFLAGS+=-mxgot -mllvm -mxmxgot
CFLAGS+=	-DCRT_IRELOC_SUPPRESS -DCRT_ATEXIT_SUPPRESS

.include <bsd.lib.mk>
