# Created by: Jan Stocker <Jan.Stocker@t-online.de>
# $FreeBSD$

PORTNAME=	thudboard
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.million.nl/file/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	The Discworld Boardgame Board

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter

NO_WRKSUBDIR=	yes
USES=		python

SUB_FILES=	thudboard

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|file:.*/docs|file://${DOCSDIR}|' \
		${WRKDIR}/thud.py

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC} 2>/dev/null

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/thudboard ${STAGEDIR}${PREFIX}/bin/thudboard
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/*.py ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/*.pyc ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKDIR}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.	for d in koomvalley img
	@${MKDIR} ${STAGEDIR}${DATADIR}/${d}
	@(cd ${WRKDIR}/${d} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/${d})
.	endfor

.include <bsd.port.mk>
