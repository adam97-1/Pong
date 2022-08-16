TEMPLATE = app
CONFIG += console c++11 static
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_LFLAGS += -static-libgcc

OBJECTS_DIR = ./Binary/Obj

win32{
    DESTDIR = ./Binary/win/
    INCLUDEPATH += C:/Lib/SFML-2.5.1/include
    INCLUDEPATH += ./inc
    LIBS += -LC:/Lib/SFML-2.5.1/lib
    LIBS += -LC:/Lib/SFML-2.5.1/bin
    CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
    CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
}

unix{
    DESTDIR = ./Binary/unix
    INCLUDEPATH += ./inc
    LIBS += -lsfml-audio
    LIBS += -lsfml-graphics
    LIBS += -lsfml-network
    LIBS += -lsfml-window
    LIBS += -lsfml-system
}

SOURCES += \
    src/gamebounds.cpp \
    src/Gui/gameview.cpp \
    src/Gui/settingsmenu.cpp \
    src/Gui/mainmenu.cpp \
    src/Gui/graphicInterface.cpp \
    src/main.cpp \
    src/Gui/view.cpp \
    src/Gui/text.cpp \
    src/ball.cpp \
    src/player.cpp \
    src/racket.cpp

HEADERS += \
    inc/gamebounds.h \
    inc/Gui/gameview.h \
    inc/Gui/graphicInterface.h \
    inc/Gui/view.h \
    inc/Gui/mainmenu.h \
    inc/Gui/text.h \
    inc/Gui/settingsmenu.h \
    inc/ball.h \
    inc/player.h \
    inc/racket.h
