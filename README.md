# Pong

## Introduction
My pong is a new version of an old game. The original Pong was created by Atari in 1972. This version of Pong is my second iteration of the game. The first version was created in C++ language and displayed only in the terminal.

## Screenshot

Game menu                  |       Settings menu       |        Game
:-------------------------:|:-------------------------:|:-------------------------:
![pong2](https://user-images.githubusercontent.com/75588591/219857763-e184382c-b3cf-4506-86a2-4a3ae87be2da.png)  |  ![pong3](https://user-images.githubusercontent.com/75588591/219858188-7478df13-ccbf-40d7-b5ae-f20981ed2b5f.png)  | ![pong1](https://user-images.githubusercontent.com/75588591/219858190-6a590528-51ab-4693-8b96-529adda2d35c.png)

## Instructions for compilation

To compile this project, you need to install the SFML library (I used SFML 2.5.1). You can open this project in Qt Creator.

### Linux
1. SFML installation: https://www.sfml-dev.org/tutorials/2.5/start-linux.php
2. Open the project in Qt Creator and run.


### Windows
1. Download SFML for MinGW: https://www.sfml-dev.org/download.php
2. Extract ZIP
3. Open Pong.pro
4. Change path to INCLUDEPATH and LIBS on extract path to SFML

    ```
        win32{
        DESTDIR = ./Binary/win/
        INCLUDEPATH += C:/Lib/SFML-2.5.1/include
        INCLUDEPATH += ./inc
        LIBS += -LC:/Lib/SFML-2.5.1/lib
        LIBS += -LC:/Lib/SFML-2.5.1/bin
        CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
        CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
    }
5. Open the project in Qt Creator and run.     

