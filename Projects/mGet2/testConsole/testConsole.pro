#-------------------------------------------------
#
# Project created by QtCreator 2015-06-18T00:30:56
#
#-------------------------------------------------

QT       += core network sql

QT       -= gui

TARGET = testConsole
CONFIG   += console C++11
CONFIG   -= app_bundle

INCLUDEPATH += ../mGetLib
LIBS += -L../build-mGetLib-Desktop-Debug -lmGet

TEMPLATE = app


SOURCES += main.cpp
