# Created by: gahr
# $FreeBSD$

PORTNAME=	libgroove
PORTVERSION=	4.2.1
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio dispatching library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libchromaprint.so:${PORTSDIR}/audio/chromaprint \
		libebur128.so:${PORTSDIR}/audio/libebur128 \
		libspeexdsp.so:${PORTSDIR}/audio/speexdsp

USE_GITHUB=	yes
GH_ACCOUNT=	andrewrk

USES=		cmake:outsource
USE_SDL=	sdl2
USE_LDCONFIG=	yes

PLIST_SUB+=	VER1=${PORTVERSION:R:R} \
		VER3=${PORTVERSION}

.include <bsd.port.mk>
