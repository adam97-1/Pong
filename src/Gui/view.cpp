#include "Gui/view.h"
#include <iostream>
#include <vector>
#include <assert.h>

View::View(sf::RenderWindow & window) : m_window(window)
{

}

View::~View()
{

}

void View::handleInputKeyboard()
{
    if(pressedKey(sf::Keyboard::Key::Up))
    {
        setSelectMenuOptions((getSelectMenuOptions() + 1 )% 7);
        std::cout << "m_selectMenuOptions: " << getSelectMenuOptions() << std::endl;
    }
    if(releasedKey(sf::Keyboard::Key::Down))
    {
        setSelectMenuOptions((getSelectMenuOptions() - 1 )% 7);
        std::cout << "m_selectMenuOptions: " << getSelectMenuOptions() << std::endl;
    }
}

bool View::pressedKey(const sf::Keyboard::Key key) const
{
    static std::vector<bool> oldStateKey(sf::Keyboard::Key::KeyCount, false);
    bool stateKey = sf::Keyboard::isKeyPressed(key);
    bool tempResult = (!oldStateKey.at(key+1) && stateKey);
    oldStateKey.at(key+1) = stateKey;
    return tempResult;
}

bool View::releasedKey(const sf::Keyboard::Key key) const
{
    static std::vector<bool> oldStateKey(sf::Keyboard::Key::KeyCount, false);
    bool stateKey = sf::Keyboard::isKeyPressed(key);
    bool tempResult = (oldStateKey.at(key+1) && !stateKey);
    oldStateKey.at(key+1) = stateKey;
    return tempResult;
}

void View::setSelectMenuOptions(const int selectMenuOptions)
{
    if(selectMenuOptions > getCountMenuOptions())
        m_selectMenuOptions = 0;
    else if(selectMenuOptions < 0)
        m_selectMenuOptions = getCountMenuOptions();
    else
        m_selectMenuOptions = selectMenuOptions;
}

int View::getSelectMenuOptions() const
{
    return m_selectMenuOptions;
}

void View::setCountMenuOptions(const int countMenuOptions)
{
    if(countMenuOptions < 0)
    {
        std::cout << "void View::setCountMenuOptions(const int countMenuOptions): countMenuOptions is negative value";
    }
    m_countMenuOptions = countMenuOptions;
}

int View::getCountMenuOptions() const
{
    return m_countMenuOptions;
}

sf::RenderWindow &View::accessWindow()
{
    return m_window;
}



