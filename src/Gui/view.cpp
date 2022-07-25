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
        setSelectMenuOptions((getSelectMenuOptions() - 1 )% 7);
        std::cout << "m_selectMenuOptions: " << getSelectMenuOptions() << std::endl;
    }
    if(pressedKey(sf::Keyboard::Key::Down))
    {
        setSelectMenuOptions((getSelectMenuOptions() + 1 )% 7);
        std::cout << "m_selectMenuOptions: " << getSelectMenuOptions() << std::endl;
    }
}

bool View::pressedKey(const sf::Keyboard::Key key) const

{
    static std::vector<bool> oldStateKey(101, false);
    bool stateKey = sf::Keyboard::isKeyPressed(key);
    bool tempResult = (!oldStateKey.at(key+1) && stateKey);
    oldStateKey.at(key+1) = stateKey;
    return tempResult;
}

bool View::releasedKey(const sf::Keyboard::Key key) const
{
    static std::vector<bool> oldStateKey(101, false);
    bool stateKey = sf::Keyboard::isKeyPressed(key);
    bool tempResult = (oldStateKey.at(key+1) && !stateKey);
    oldStateKey.at(key+1) = stateKey;
    return tempResult;
}

void View::setSelectMenuOptions(const int selectMenuOptions)
{
    if(selectMenuOptions > getCountMenuOptions()-1)
        m_selectMenuOptions = 0;
    else if(selectMenuOptions < 0)
        m_selectMenuOptions = getCountMenuOptions()-1;
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

void View::setDisplayNextView(const GraphicView view)
{
    m_displayNextView = view;
}

View::GraphicView View::getDisplayNextView() const
{
    return m_displayNextView;
}

sf::RenderWindow &View::accessWindow()
{
    return m_window;
}

void View::setMenuTextPosition()
{
    sf::Vector2u windowSize = accessWindow().getSize();
    sf::FloatRect rectTitle = m_title.getLocalBounds();
    m_title.setOrigin(rectTitle.width/2, rectTitle.top);
    m_title.setPosition(windowSize.x/2, windowSize.y/10);

    int maxWidthText = 0;
    for(const auto & text : m_menuOptions)
    {
        sf::FloatRect rectText = text.getLocalBounds();
        if(maxWidthText < rectText.width)
            maxWidthText = rectText.width;
    }

    int index = 0;
    for(auto & text : m_menuOptions)
    {
        text.setPosition((windowSize.x - maxWidthText)/2, windowSize.y/10+index*text.getCharacterSize()*1.5+50);
        index++;
    }
}

void View::updateMenuTextLook()
{
    for(auto & text : m_menuOptions)
        text.setFillColor(sf::Color::White);
    m_menuOptions.at(getSelectMenuOptions()).setFillColor(sf::Color::Red);
}


