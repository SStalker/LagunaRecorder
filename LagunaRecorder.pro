#-------------------------------------------------
#
# Project created by QtCreator 2013-06-08T13:32:04
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LagunaRecorder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camera.cpp \
    viewfinder.cpp

HEADERS  += mainwindow.h \
    camera.h \
    viewfinder.h

FORMS    += mainwindow.ui
