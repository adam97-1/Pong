#include "Gui/view.h"
#include <iostream>
#include <vector>

View::View()
{

}

View::~View()
{

}

void View::handleInputKeyboard()
{
    if(pressedKey(sf::Keyboard::Key::Up))
    {
        m_selectMenuOptions = (++m_selectMenuOptions % 7);
        std::cout << "m_selectMenuOptions: " << m_selectMenuOptions << std::endl;
    }
    if(releasedKey(sf::Keyboard::Key::Down))
    {
        m_selectMenuOptions = (--m_selectMenuOptions % 7);
        std::cout << "m_selectMenuOptions: " << m_selectMenuOptions << std::endl;
    }
}

bool View::pressedKey(sf::Keyboard::Key key)
{
    static std::vector<bool> oldStateKey(sf::Keyboard::Key::KeyCount, false);
    bool stateKey = sf::Keyboard::isKeyPressed(key);
    bool tempResult = (!oldStateKey.at(key+1) && stateKey);
    oldStateKey.at(key+1) = stateKey;
    return tempResult;
}

bool View::releasedKey(sf::Keyboard::Key key)
{
    static std::vector<bool> oldStateKey(sf::Keyboard::Key::KeyCount, false);
    bool stateKey = sf::Keyboard::isKeyPressed(key);
    bool tempResult = (oldStateKey.at(key+1) && !stateKey);
    oldStateKey.at(key+1) = stateKey;
    return tempResult;
}



