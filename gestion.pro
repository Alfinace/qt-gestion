#-------------------------------------------------
#
# Project created by QtCreator 2023-10-14T22:24:46
#
#-------------------------------------------------

QT       += core gui
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestion
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    formstudent.cpp \
    dialogformstudent.cpp

HEADERS  += mainwindow.h \
    formstudent.h \
    dialogformstudent.h \
    connection_mysql.h

FORMS    += mainwindow.ui \
    formstudent.ui \
    dialogformstudent.ui

OTHER_FILES +=
