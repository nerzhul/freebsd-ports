# Created by: Andrey Slusar <anray@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imagick
DISTVERSION=	3.1.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Provides a wrapper to the ImageMagick/GraphicsMagick library

LICENSE=	PHP301

OPTIONS_DEFINE=	X11

X11_LIB_DEPENDS=	libMagickWand-6.so:${PORTSDIR}/graphics/ImageMagick
X11_LIB_DEPENDS_OFF=	libMagickWand-6.so:${PORTSDIR}/graphics/ImageMagick-nox11

USES=		pkgconfig tar:tgz
USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

.include <bsd.port.mk>
