TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    message.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

CONFIG +=C++11

HEADERS += \
    message.h
