# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	LaTeX-Driver
PORTVERSION=	0.20.02
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module of LaTeX Driver

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Exception-Class>=0:${PORTSDIR}/devel/p5-Exception-Class \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-IPC-ShellCmd>=0:${PORTSDIR}/devel/p5-IPC-ShellCmd \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_TEX=	latex

.include <bsd.port.mk>
