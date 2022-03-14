TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= debug warn_on qt thread staticlib widgets
QT += widgets xml printsupport
HEADERS	+= canvaselements.h \
	datareader.h \
	defs.h \
	diagram.h \
	element.h \
	layer.h \
	matrix.h \
	parameters.h \
	pattern.h \
	permutation.h \
	pgonedge.h \
	poincareview.h \
	regularpgon.h \
	transformation.h \
	ui_hyperart.h \
	hyperart.h \
	diagramview.h \
	irregularpgon.h

SOURCES	+= canvaselements.cpp \
	hyperart.cpp \
	datareader.cpp \
	diagram.cpp \
	element.cpp \
	layer.cpp \
	main.cpp \
	matrix.cpp \
	parameters.cpp \
	pattern.cpp \
	permutation.cpp \
	pgonedge.cpp \
	poincareview.cpp \
	regularpgon.cpp \
	transformation.cpp \
	defs.cpp \
	diagramview.cpp \
	irregularpgon.cpp

FORMS	= hyperart.ui

IMAGES	= butter.xpm \
	fileopen.xpm \
	fileprint.xpm \
	filesave.xpm \
	anim-next.xpm \
	anim-pause.xpm \
	anim-play.xpm \
	anim-prev.xpm \
	anim-stop.xpm \
	zoom-default.xpm \
	zoom-in.xpm \
	zoom-out.xpm

# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: .
# Target is an application:  ./hyperart

TARGET = ./hyperart


