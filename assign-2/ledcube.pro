######################################################################
# Automatically generated by qmake (2.01a) Wed Mar 5 00:29:51 2014
######################################################################

QT += core gui opengl

TEMPLATE = app
TARGET = 
DEPENDPATH += . simulation
INCLUDEPATH += . simulation

# Input
HEADERS     += \
    mywidget.h \
    simulation/mainwidget.h \
    simulation/geometryengine.h
SOURCES     += \
    main.cpp \
    mywidget.cpp \
    simulation/mainwidget.cpp \
    simulation/geometryengine.cpp
RESOURCES += \
    ledcube.qrc \
    simulation/shaders.qrc \
    simulation/textures.qrc
OTHER_FILES += \
    simulation/vshader.glsl \
    simulation/fshader.glsl
