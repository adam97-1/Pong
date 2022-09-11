#ifndef SETTINGSEVENTLISTENERS_H
#define SETTINGSEVENTLISTENERS_H

#include <SFML/Graphics.hpp>

class SettingsEventListeners
{
public:
    virtual void onSettingsChangeResolution(sf::VideoMode){};
    virtual void onSettingsChangeAudio(int){};
};

#endif // SETTINGSEVENTLISTENERS_H
