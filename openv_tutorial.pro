#-------------------------------------------------
#
# Project created by QtCreator 2015-09-02T10:27:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = openv_tutorial
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

INCLUDEPATH += C:\\opencv300_x32_vc2013\\include \
                C:\\opencv300_x32_vc2013\\include\\opencv \
                C:\\opencv300_x32_vc2013\\include\\opencv2 \

LIBS +=  C:\\opencv300_x32_vc2013\\lib\\opencv_world300.lib \
         C:\\opencv300_x32_vc2013\\lib\\opencv_ts300.lib \
         C:\\opencv300_x32_vc2013\\lib\\opencv_world300d.lib \
         C:\\opencv300_x32_vc2013\\lib\\opencv_ts300d.lib



FORMS    += mainwindow.ui
