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
    Pathfinder.cpp \
    Move.cpp \    
    mapwidget.cpp \
    mapscene.cpp \
    range.cpp \
    fight.cpp \
    shootablerange.cpp \
##core
#core/world
    core/world/world.cpp \
    core/world/Coordinate.cpp \
    core/world/Tile.cpp \
    core/world/Map.cpp \
#core/objects
    core/objects/holdableobject.cpp \
    core/objects/wearable.cpp \
    core/objects/weapon.cpp \
    core/objects/Object.cpp \
#core/living
    core/living/nonplayercharacter.cpp \
    core/living/fighter.cpp \
    core/living/player.cpp \
    core/living/monster.cpp \
    core/living/Living.cpp \
#core/attack
    core/attack/attack.cpp \
    core/attack/effect.cpp \
    core/attack/damage.cpp \
    core/attack/attackvalue.cpp \
    core/attack/attackrange.cpp \
#core/spec
    core/spec/value.cpp \
    core/spec/attributs.cpp \
#core/objectManagement
    core/objectManagement/objectdrop.cpp \
    core/objectManagement/bag.cpp

HEADERS  += mainwindow.h \
    mainwindow.h \
    Pathfinder.h \
    Move.h \
    mapwidget.h \
    mapscene.h \
    range.h \
    fight.h \
    shootablerange.h \
##core
#core/world
    core/world/world.h \
    core/world/Coordinate.h \
    core/world/Tile.h \
    core/world/Map.h \
#core/objects
    core/objects/holdableobject.h \
    core/objects/wearable.h \
    core/objects/weapon.h \
    core/objects/Object.h \
#core/living
    core/living/nonplayercharacter.h \
    core/living/fighter.h \
    core/living/player.h \
    core/living/monster.h \
    core/living/Living.h \
#core/attack
    core/attack/attack.h \
    core/attack/effect.h \
    core/attack/damage.h \
    core/attack/attackvalue.h \
    core/attack/attackrange.h \
#core/spec
    core/spec/value.h \
    core/spec/attributs.h \
#core/objectManagement
    core/objectManagement/objectdrop.h \
    core/objectManagement/bag.h

FORMS    += mainwindow.ui

DISTFILES += \
    mosp.pro.user \
    map/test.map \
    calculs.txt
