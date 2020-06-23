#-------------------------------------------------
#
# Project created by QtCreator 2019-09-16T02:44:30
#
#-------------------------------------------------
CONFIG += c++11
QT += core gui opengl
LIBS += -lopengl32
LIBS   += -lglu32
LIBS   += -lglut32



//QT       += opengl

TARGET = CG_Paint
TEMPLATE = app


SOURCES += main.cpp\
    JanelaPrincipal.cpp \
    PaintTela.cpp

HEADERS  += \
    JanelaPrincipal.h \
    PaintTela.h

FORMS    += \
    JanelaPrincipal.ui
