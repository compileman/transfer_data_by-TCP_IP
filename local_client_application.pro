QT += core
QT -= gui

CONFIG += c++11

TARGET = local_client_application
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    local_client.cpp \
    ourdata.cpp

HEADERS += \
    local_client.h \
    ourdata.h


#//////////////////////////////////////

QT += network

QT += widgets

QT += core
