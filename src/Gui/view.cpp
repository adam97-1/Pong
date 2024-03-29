#include "Gui/view.h"
#include <iostream>
#include <vector>

View::View(sf::RenderWindow & window) : m_window(window)
{
    m_audioChangeOptions.openFromFile("./Music/changeOptions.waw");
    m_audioSelectOption.openFromFile("./Music/select.waw");
}

View::~View()
{

}

void View::handleInputKeyboard()
{
    // Reset audio
    m_audioChangeOptions.stop();
    m_audioSelectOption.stop();

    // Check for pressed keys and change selected option in menu accordingly.
    if(holdKay(sf::Keyboard::Key::Up, sf::milliseconds(200)) || holdKay(sf::Keyboard::Key::W, sf::milliseconds(200)))
    {
        setSelectMenuOptions(getSelectMenuOptions() - 1 );
        updateMenuTextLook();                                   // Update look of all text in menu.
    }
    if(holdKay(sf::Keyboard::Key::Down, sf::milliseconds(200)) || holdKay(sf::Keyboard::Key::S, sf::milliseconds(200)))
    {
        setSelectMenuOptions(getSelectMenuOptions() + 1 );
        updateMenuTextLook();                                   // Update look of all text in menu.
    }
}

bool View::pressedKey(const sf::Keyboard::Key key) const

{
    static std::vector<bool> oldStateKey(101, false);           // Variable stores states of all keys in keyboard. This variable stores states before that method executed.
                                                                // Enum start with sf::Keyboard::Key::Unknown = -1, for that you can't use this value to method at(sf::Keyboard::Key::Unknown).
                                                                // Then you have to add 1 to key.

    bool stateKey = sf::Keyboard::isKeyPressed(key);            // Check actual state of key.
    bool tempResult = (!oldStateKey.at(key+1) && stateKey);     // Compare old state of key with actual state. If key was released and is pressed then return true.
    oldStateKey.at(key+1) = stateKey;                           // Update state of key.
    return tempResult;
}

bool View::releasedKey(const sf::Keyboard::Key key) const
{
    static std::vector<bool> oldStateKey(101, false);           // Variable stores states of all keys in keyboard. This variable stores states before that method executed.
                                                                // Enum start with sf::Keyboard::Key::Unknown = -1, for that you can't use this value to method at(sf::Keyboard::Key::Unknown).
                                                                // Then you have to add 1 to key.
    bool stateKey = sf::Keyboard::isKeyPressed(key);            // Check actual state of key.
    bool tempResult = (oldStateKey.at(key+1) && !stateKey);     // Compare old state key with actual state. If key was pressed and is released then return true.
    oldStateKey.at(key+1) = stateKey;                           // Update state of key.
    return tempResult;
}

bool View::holdKay(const sf::Keyboard::Key key, sf::Time holdTime) const
{
    static std::vector<bool> oldStateKey(101, false);                   // Variable stores states of all keys in keyboard. This variable stores states before that method executed.
                                                                        // Enum start with sf::Keyboard::Key::Unknown = -1, for that you can't use this value to method at(sf::Keyboard::Key::Unknown).
                                                                        // Then you have to add 1 to key.

    static sf::Clock pressTime;                                         // Variable stored time since key press.
    bool stateKey = sf::Keyboard::isKeyPressed(key);                    // Check actual state of key.
    bool tempResult = (!oldStateKey.at(key+1) && stateKey);             // Compare old state key witch actual state. If key was released and is pressed then return true.
    oldStateKey.at(key+1) = stateKey;                                   // Update state of key.

    // If key is held by holdTime. Return true and reset time;
    if(stateKey && pressTime.getElapsedTime() > holdTime)
    {
        pressTime.restart();
        return true;
    }
    return tempResult;
}

void View::setSelectMenuOptions(const int selectMenuOptions)
{
    m_audioChangeOptions.play();
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
    m_title.setPosition(windowSize.x/2, windowSize.y/10);   // Sets title in the top-center position of the view.


    // Checks max width of all options text in menu.
    int maxWidthText = 0;
    for(const auto & text : m_menuOptions)
    {
        sf::FloatRect rectText = text.getLocalBounds();
        if(maxWidthText < rectText.width)
            maxWidthText = rectText.width;
    }

    // Set positions of all options text according to maxWidthText.
    int index = 0;
    for(auto & text : m_menuOptions)
    {
        text.setPosition((windowSize.x - maxWidthText)/2, windowSize.y/10+index*text.getCharacterSize()*1.5 + m_title.getCharacterSize()*2);
        index++;
    }
}

void View::updateMenuTextLook()
{
    for(auto & text : m_menuOptions)
    {
        text.setFillColor(sf::Color::White);                        // Reset all text color.
    }

    // Set red color for selected option in menu.
    m_menuOptions.at(getSelectMenuOptions()).setFillColor(sf::Color::Red);
}

void View::onSettingsChangeResolution(sf::VideoMode videoMode)
{
    m_title.setCharacterSize(videoMode.height/10);
    for(auto & text : m_menuOptions)
    {
        text.setCharacterSize(videoMode.height/20);       // Adapts size of text for actual resolution.
    }
    setMenuTextPosition();
}

void View::onSettingsChangeAudio(int volume)
{
    m_audioChangeOptions.setVolume(volume);
    m_audioSelectOption.setVolume(volume);
}


