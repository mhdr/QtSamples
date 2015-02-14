#-------------------------------------------------
#
# Project created by QtCreator 2015-02-13T20:00:16
#
#-------------------------------------------------

QT       += core
QT       += network

QT       -= gui

TARGET = Server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp
CONFIG +=c++14

HEADERS += \
    myserver.h
