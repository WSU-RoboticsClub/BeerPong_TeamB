#-------------------------------------------------
#
# Project created by QtCreator 2015-12-19T16:13:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BeerPong_GUI
TEMPLATE = app

INCLUDEPATH += serial/

SOURCES += main.cpp\
        mainwindow.cpp \
    serial/src/Serial.cpp \
    serial/src/Packetizer.cpp \
    portreader.cpp \
    pid_controller.cpp

HEADERS  += mainwindow.h \
    serial/include/Serial.hpp \
    serial/include/Packetizer.hpp \
    portreader.hpp \
    pid_controller.h

FORMS    += mainwindow.ui
