#-------------------------------------------------
#
# Project created by QtCreator 2022-06-25T19:08:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dazuoye2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adddishes.cpp \
    history.cpp \
    set.cpp \
    recommend.cpp \
    dish.cpp \
    assess.cpp

HEADERS  += mainwindow.h \
    adddishes.h \
    history.h \
    set.h \
    recommend.h \
    dish.h \
    assess.h

FORMS    += mainwindow.ui \
    adddishes.ui \
    history.ui \
    set.ui \
    recommend.ui \
    dish.ui \
    assess.ui
