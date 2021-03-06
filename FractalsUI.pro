#-------------------------------------------------
#
# Project created by QtCreator 2017-01-09T15:20:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FractalsUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH = "C:/Program Files (x86)/Windows Kits/10/Include/10.0.10240.0/ucrt"

SOURCES += main.cpp \
    mandelbrotwidget.cpp \
    renderthread.cpp \
    complex.cpp \
    feature_wind.cpp

HEADERS  += \
    mandelbrotwidget.h \
    renderthread.h \
    complex.h \
    feature_wind.h

FORMS    += \
    mandelbrotwidget.ui
