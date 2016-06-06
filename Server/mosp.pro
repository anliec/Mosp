#-------------------------------------------------
#
# Project created by QtCreator 2015-08-08T13:26:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mosp
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    Tile.cpp \
    Pathfinder.cpp \
    Object.cpp \
    Move.cpp \
    Map.cpp \
    Living.cpp \
    Coordinate.cpp \
    mapwidget.cpp \
    mapscene.cpp \
    world.cpp \
    value.cpp \
    range.cpp \
    effect.cpp \
    damage.cpp \
    attack.cpp \
    attributs.cpp \
    holdableobject.cpp \
    wearable.cpp \
    weapon.cpp \
    nonplayercharacter.cpp \
    fighter.cpp \
    objectdrop.cpp \
    player.cpp \
    monster.cpp \
    fight.cpp \
    attackvalue.cpp \
    attackrange.cpp \
    bag.cpp \
    shootablerange.cpp

HEADERS  += mainwindow.h \
    Tile.h \
    Pathfinder.h \
    Object.h \
    Move.h \
    Map.h \
    Living.h \
    Coordinate.h \
    mapwidget.h \
    mapscene.h \
    world.h \
    value.h \
    range.h \
    effect.h \
    damage.h \
    attack.h \
    attributs.h \
    holdableobject.h \
    wearable.h \
    weapon.h \
    nonplayercharacter.h \
    fighter.h \
    objectdrop.h \
    player.h \
    monster.h \
    fight.h \
    attackvalue.h \
    attackrange.h \
    bag.h \
    shootablerange.h

FORMS    += mainwindow.ui

DISTFILES += \
    mosp.pro.user \
    map/test.map \
    calculs.txt
