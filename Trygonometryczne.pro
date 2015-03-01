#-------------------------------------------------
#
# Project created by QtCreator 2015-02-24T13:22:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Trygonometryczne
ICON = ikona.png
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wyniki.cpp \
    dialog.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    wyniki.h \
    dialog.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    dialog.ui 
