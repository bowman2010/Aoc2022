INCLUDEPATH += ../Utils/
TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        hillclimbing.cpp \
        main.cpp

HEADERS += \
    hillclimbing.h
