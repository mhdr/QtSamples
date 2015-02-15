#-------------------------------------------------
#
# Project created by QtCreator 2015-02-06T17:51:58
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PmpalerPipe
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    player.cpp

HEADERS  += widget.h \
    player.h

FORMS +=

CONFIG += c++14
