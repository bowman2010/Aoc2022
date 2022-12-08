INCLUDEPATH += ../Utils/
TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        fssim.cpp \
        main.cpp \
        nospaceleft.cpp

HEADERS += \
    fssim.h \
    nospaceleft.h
