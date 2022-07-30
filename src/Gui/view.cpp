#include "Gui/view.h"
#include <iostream>
#include <vector>

View::View(sf::RenderWindow & window) : m_window(window)
{

}

View::~View()
{

}

void View::handleInputKeyboard()
{
    // Check press keys and change selected option in menu.
    if(pressedKey(sf::Keyboard::Key::Up) || pressedKey(sf::Keyboard::Key::W))
    {
        setSelectMenuOptions(getSelectMenuOptions() - 1 );
//        std::cout << "m_selectMenuOptions: " << getSelectMenuOptions() << std::endl;
    }
    if(pressedKey(sf::Keyboard::Key::Down) || pressedKey(sf::Keyboard::Key::S))
    {
        setSelectMenuOptions(getSelectMenuOptions() + 1 );
//        std::cout << "m_selectMenuOptions: " << getSelectMenuOptions() << std::endl;
    }
}

bool View::pressedKey(const sf::Keyboard::Key key) const

{
    static std::vector<bool> oldStateKey(101, false);           // Variable stored state all keys in keyboard. This variable stored state for before execute that method.
                                                                // Enum start with sf::Keyboard::Key::Unknown = -1, for that you can't use this value to method at(sf::Keyboard::Key::Unknown).
                                                                // Then you have to add 1 to key.
    bool stateKey = sf::Keyboard::isKeyPressed(key);            // Check actual state of key.
    bool tempResult = (!oldStateKey.at(key+1) && stateKey);     // Compare old state key witch actual state. If key was released and is pressed then return true.
    oldStateKey.at(key+1) = stateKey;                           // Update state of key.
    return tempResult;
}

bool View::releasedKey(const sf::Keyboard::Key key) const
{
    static std::vector<bool> oldStateKey(101, false);           // Variable stored state all keys in keyboard. This variable stored state for before execute that method.
                                                                // Enum start with sf::Keyboard::Key::Unknown = -1, for that you can't use this value to method at(sf::Keyboard::Key::Unknown).
                                                                // Then you have to add 1 to key.
    bool stateKey = sf::Keyboard::isKeyPressed(key);            // Check actual state of key.
    bool tempResult = (oldStateKey.at(key+1) && !stateKey);     // Compare old state key witch actual state. If key was pressed and is released then return true.
    oldStateKey.at(key+1) = stateKey;                           // Update state of key.
    return tempResult;
}

void View::setSelectMenuOptions(const int selectMenuOptions)
{
    // This make loop on select option.
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
    sf::Vector2u windowSize = accessWindow().getSize();     // Gets resolution of window.
    sf::FloatRect rectTitle = m_title.getLocalBounds();     // Gets size of m_title.
    m_title.setOrigin(rectTitle.width/2, rectTitle.top);    // Changes origin point of the title.
    m_title.setPosition(windowSize.x/2, windowSize.y/10);   // Sets positions title on top and center win widow.

    // Checks max width witch all options text in menu.
    int maxWidthText = 0;
    for(const auto & text : m_menuOptions)
    {
        sf::FloatRect rectText = text.getLocalBounds();
        if(maxWidthText < rectText.width)
            maxWidthText = rectText.width;
    }

    // Set positions of all options text on the basis of max width texts.
    int index = 0;
    for(auto & text : m_menuOptions)
    {
        text.setPosition((windowSize.x - maxWidthText)/2, windowSize.y/10+index*text.getCharacterSize()*1.5+50);
        index++;
    }
}

void View::updateMenuTextLook()
{
    // Reset all text color.
    for(auto & text : m_menuOptions)
        text.setFillColor(sf::Color::White);

    // Set color Red for selected option in menu.
    m_menuOptions.at(getSelectMenuOptions()).setFillColor(sf::Color::Red);
}


