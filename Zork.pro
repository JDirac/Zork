TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Command.cpp \
        CommandWords.cpp \
        Enemy.cpp \
        Entity.cpp \
        NPC.cpp \
        Parser.cpp \
        Player.cpp \
        Room.cpp \
        Vendor.cpp \
        ZorkUL.cpp \
        item.cpp

DISTFILES += \
    CMakeLists.txt.user \
    Zork.pro.user

HEADERS += \
    Command.h \
    CommandWords.h \
    Enemy.h \
    Entity.h \
    NPC.h \
    Parser.h \
    Player.h \
    Room.h \
    Vendor.h \
    ZorkUL.h \
    item.h
