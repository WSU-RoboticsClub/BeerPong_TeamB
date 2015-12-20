#-------------------------------------------------
#
# Project created by QtCreator 2015-12-19T16:13:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BeerPong_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Packetizer.cpp \
    Serial.cpp

HEADERS  += mainwindow.h \
    Packetizer.hpp \
    Serial.hpp

FORMS    += mainwindow.ui
