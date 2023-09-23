TARGET = lifeCore
TEMPLATE = lib

QT += widgets
CONFIG += staticlib
CONFIG += c++20

SOURCES += \
    GameModel.cpp \
    GameView.cpp

HEADERS += \
    GameModel.h \
    GameView.h
