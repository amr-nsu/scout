#-------------------------------------------------
#
# Project created by QtCreator 2018-10-30T17:00:03
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = control_panel
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frame_123.cpp

HEADERS  += mainwindow.h \
    frame_123.h

FORMS    += mainwindow.ui
