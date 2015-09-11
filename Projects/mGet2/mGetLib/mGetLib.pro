#-------------------------------------------------
#
# Project created by QtCreator 2015-06-16T20:26:31
#
#-------------------------------------------------

QT       += network sql

QT       -= gui

TARGET = mGet
TEMPLATE = lib
CONFIG += staticlib C++11

SOURCES += \
    httpclient.cpp \
    environment.cpp \
    downloadinfo.cpp

HEADERS += \
    httpclient.h \
unix { \
    environment.h \
    downloadinfo.h
    target.path = /usr/lib
    INSTALLS += target
}
