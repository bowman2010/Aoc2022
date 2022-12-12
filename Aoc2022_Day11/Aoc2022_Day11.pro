INCLUDEPATH += ../Utils/
TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        monkey.cpp \
        monkeygame.cpp

HEADERS += \
    monkey.h \
    monkeygame.h
