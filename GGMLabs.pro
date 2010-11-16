#-------------------------------------------------
#
# Project created by QtCreator 2010-11-11T19:49:20
#
#-------------------------------------------------

QT       += core gui

TARGET = AGF
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    AGF/agfgraphicsview.cpp \
    AGF/agfgraphicsitem.cpp \
    AGF/transformations/agfprojective.cpp \
    AGF/transformations/agfeuclidean.cpp \
    AGF/transformations/agfaffine.cpp \
    AGF/items/agfgrid.cpp \
    shape.cpp

HEADERS  += mainwindow.h \
    AGF/agfgraphicsview.h \
    AGF/agfgraphicsitem.h \
    AGF/transformations/agfprojective.h \
    AGF/transformations/agfeuclidean.h \
    AGF/transformations/agfaffine.h \
    AGF/items/agfgrid.h \
    mainwindow.h \
    shape.h

FORMS    += mainwindow.ui

RESOURCES += \
    yuriy.qrc

OTHER_FILES += \
    images/stop.png \
    images/shape.png \
    images/scale.png \
    images/rotate1.png \
    images/rotate.png \
    images/reset.png \
    images/play.png \
    images/params.png \
    images/move.png \
    images/magnifier.png \
    images/hand.png \
    images/grid.png
