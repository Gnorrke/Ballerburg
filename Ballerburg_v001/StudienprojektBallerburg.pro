TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    game.cpp \
    graphic.cpp \
    sprite.cpp \
    animatedsprite.cpp \
    input.cpp \
    tracer.cpp \
    sound.cpp \
    backdrop.cpp \
    mountain.cpp \
    cannonball.cpp \
    mountainblock.cpp \
    castle.cpp \
    block.cpp \
    castleblock.cpp \
    cannon.cpp \
    map.cpp \
    king.cpp \
    startmenu.cpp \
    button.cpp \
    player.cpp

LIBS += -lmingw32 -lSDLmain -lSDL -mwindows -lSDL_mixer

LIBS += -LC:/Resources/SDL-1.2.15/lib libSDLmain libSDL.dll SDL_mixer.dll
INCLUDEPATH += "C:/Resources/SDL-1.2.15/include"

HEADERS += \
    game.h \
    graphic.h \
    sprite.h \
    animatedsprite.h \
    input.h \
    rectangle.h \
    tracer.h \
    sound.h \
    backdrop.h \
    mountain.h \
    cannonball.h \
    circle.h \
    mountainblock.h \
    castle.h \
    block.h \
    castleblock.h \
    cannon.h \
    map.h \
    king.h \
    startmenu.h \
    button.h \
    player.h


