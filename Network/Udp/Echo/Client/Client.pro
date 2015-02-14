#-------------------------------------------------
#
# Project created by QtCreator 2015-02-13T20:15:56
#
#-------------------------------------------------

QT       += core
QT       += network

QT       -= gui

TARGET = Client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myclient.cpp
CONFIG +=c++14

HEADERS += \
    myclient.h
