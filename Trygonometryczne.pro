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

SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/wyniki.cpp \
    src/dialog.cpp \
    src/qcustomplot.cpp

HEADERS  += headers/mainwindow.h \
    headers/wyniki.h \
    headers/dialog.h \
    headers/qcustomplot.h

FORMS    += ui/mainwindow.ui \
    ui/dialog.ui
