#-------------------------------------------------
#
# Project created by QtCreator 2015-10-01T13:43:03
#
#-------------------------------------------------

CONFIG += c++11

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Journey_CSULB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    data.cpp \
    cards.cpp \
    chipbox.cpp \
    discardcard.cpp

HEADERS  += mainwindow.h \
    data.h \
    cards.h \
    chipbox.h \
    discardcard.h

FORMS    += mainwindow.ui \
    chipbox.ui \
    discardcard.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
