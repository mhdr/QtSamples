#-------------------------------------------------
#
# Project created by QtCreator 2015-06-16T20:33:33
#
#-------------------------------------------------

QT       += core testlib network

QT       -= gui

TARGET = UnitTest
CONFIG   += console C++11
CONFIG   -= app_bundle

INCLUDEPATH += ../mGetLib
LIBS += -L../build-mGetLib-Desktop-Debug -lmGet

TEMPLATE = app

SOURCES += main.cpp \
    httpclienttests.cpp

OTHER_FILES +=

HEADERS += \
    httpclienttests.h
