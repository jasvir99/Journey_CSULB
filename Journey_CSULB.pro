#-------------------------------------------------
#
# Project created by QtCreator 2015-10-01T13:43:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Journey_CSULB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    data.cpp \
    cards.cpp

HEADERS  += mainwindow.h \
    data.h \
    cards.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
