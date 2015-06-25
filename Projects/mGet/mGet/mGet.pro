#-------------------------------------------------
#
# Project created by QtCreator 2015-06-18T19:38:36
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = mGet
CONFIG   += console C++11
CONFIG   -= app_bundle

INCLUDEPATH += ../mGetLib
LIBS += -L../build-mGetLib-Desktop-Debug -lmGet

TEMPLATE = app


SOURCES += main.cpp \
    download.cpp

HEADERS += \
    download.h
