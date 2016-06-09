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
##core
#core/world
    core/world/Coordinate.cpp \
    core/world/Tile.cpp \
    core/world/Map.cpp \
#core/objects
    core/objects/Object.cpp \
#core/living
    core/living/Living.cpp \
#core/attack
#core/spec
    core/spec/value.cpp \
#core/objectManagement
    Fight.cpp \
    MapScene.cpp \
    MapWidget.cpp \
    Range.cpp \
    ShootableRange.cpp \
    core/attack/Attack.cpp \
    core/attack/Damage.cpp \
    core/attack/AttackRange.cpp \
    core/attack/AttackValue.cpp \
    core/attack/Effect.cpp \
    core/living/Fighter.cpp \
    core/living/Monster.cpp \
    core/living/NonPlayerCharacter.cpp \
    core/living/Player.cpp \
    core/objectManagement/Bag.cpp \
    core/objectManagement/ObjectDrop.cpp \
    core/objects/HoldableObject.cpp \
    core/objects/Weapon.cpp \
    core/objects/Wearable.cpp \
    core/spec/Attributs.cpp \
    core/world/World.cpp

HEADERS  += mainwindow.h \
    mainwindow.h \
    Pathfinder.h \
    Move.h \
##core
#core/world
    core/world/Coordinate.h \
    core/world/Tile.h \
    core/world/Map.h \
#core/objects
    core/objects/Object.h \
#core/living
    core/living/Living.h \
#core/attack
#core/spec
    core/spec/value.h \
#core/objectManagement
    core/objects/Weapon.h \
    core/objects/HoldableObject.h \
    core/spec/Attributs.h \
    core/world/World.h \
    core/objectManagement/Bag.h \
    core/objectManagement/ObjectDrop.h \
    core/living/Fighter.h \
    core/living/Monster.h \
    core/living/NonPlayerCharacter.h \
    core/living/Player.h \
    core/attack/Attack.h \
    core/attack/Damage.h \
    core/attack/Effect.h \
    Fight.h \
    MapScene.h \
    MapWidget.h \
    Range.h \
    ShootableRange.h \
    core/attack/AttackRange.h \
    core/attack/AttackValue.h \
    core/objects/Wearable.h

FORMS    += mainwindow.ui

DISTFILES += \
    mosp.pro.user \
    map/test.map \
    calculs.txt
