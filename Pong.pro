TEMPLATE = app
CONFIG += console c++11 static
CONFIG -= app_bundle
CONFIG -= qt

OBJECTS_DIR = ./Binary/Obj

win32{
    DESTDIR = ./Binary/win/
    INCLUDEPATH += C:/Lib/SFML-2.5.1/include
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
        src/Gui/graphicInterface.cpp \
        src/main.cpp

HEADERS += \
    inc/Gui/graphicInterface.h
