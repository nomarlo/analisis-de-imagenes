#-------------------------------------------------
#
# Project created by QtCreator 2015-09-21T08:50:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Test-2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dlgimage.cpp \
    mylabel.cpp \
    qcustomplot.cpp \
    histograma.cpp \
    rangos.cpp \
    convolucion.cpp

HEADERS  += mainwindow.h \
    dlgimage.h \
    mylabel.h \
    qcustomplot.h \
    histograma.h \
    rangos.h \
    convolucion.h

FORMS    += mainwindow.ui \
    dlgimage.ui \
    histograma.ui \
    rangos.ui \
    convolucion.ui
