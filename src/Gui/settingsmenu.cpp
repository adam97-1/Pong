#include "Gui/settingsmenu.h"
#include <iostream>

SettingsMenu::SettingsMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 4;              // Quantity menu options for display on this view.

    // Clear vector of the text, create new text and add this text for the vector.
    m_menuOptions.clear();
    for(int i = 0; i < quantityMenuOptions; i++)
    {
        Text *tempText_ptr = new Text;
        m_menuOptions.push_back(*tempText_ptr);
//        delete tempText_ptr;      // I don't know why this don't work.
    }
    this->setCountMenuOptions(quantityMenuOptions);             // Sets quantity menu options for display on this view.
    m_availabeResolution = sf::VideoMode::getFullscreenModes();
    accessWindow().create(sf::VideoMode(m_availabeResolution.at(getSelectResolution()).width, m_availabeResolution.at(getSelectResolution()).height
                                        , m_availabeResolution.at(getSelectResolution()).bitsPerPixel), "Pong", sf::Style::Fullscreen);
    setTextString();                                            // Sets strings for text in the view.
    setDisplayNextView(SettingsMenu::GraphicView::SETTINGS);    // Sets default next view for display.
}

void SettingsMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Draw all elements for display.
    target.draw(m_title);
    for(const auto & text : m_menuOptions)
        target.draw(text);
}

void SettingsMenu::setTextString()
{
    m_title.setString("Settings");
    m_menuOptions.at(SettingsMenuOptions::AUDIO).setString("1.   Audio   " + std::to_string(getVloumeAudio()) +'%');
    m_menuOptions.at(SettingsMenuOptions::RESOLUTION).setString("2.   Resolution  " + std::to_string(m_availabeResolution.at(getSelectResolution()).width) + 'x'
                                    + std::to_string(m_availabeResolution.at(getSelectResolution()).height)
                                    + ' ' + std::to_string(m_availabeResolution.at(getSelectResolution()).bitsPerPixel) + "Bit");
    m_menuOptions.at(SettingsMenuOptions::APPLY).setString("3.   Apply");
    m_menuOptions.at(SettingsMenuOptions::RBACK).setString("4.   Back");

}

void SettingsMenu::setVloumeAudio(int volume)
{
    if(volume > 100)
        m_audio = 100;
    else if(volume < 0)
        m_audio = 0;
    else
        m_audio = volume;
}

int SettingsMenu::getVloumeAudio()
{
    return m_audio;
}

void SettingsMenu::setSelectResolution(int select)
{
    if(select > static_cast<int>(m_availabeResolution.size())-1)
        m_selectResolution = 0;
    else if(select < 0)
        m_selectResolution = static_cast<int>(m_availabeResolution.size())-1;
    else
        m_selectResolution = select;
}

int SettingsMenu::getSelectResolution()
{
    return m_selectResolution;
}

void SettingsMenu::handleInputKeyboard()    // Check inputs for general view.
{
    // If window is actual use (isn't minimized or active). It check inputs.
    if(!accessWindow().hasFocus())
        return;
    View::handleInputKeyboard();

    // Check input special input for this view.
    //-----------------------------------------------------------------------
    if(holdKay(sf::Keyboard::Key::Left, sf::milliseconds(200)) || holdKay(sf::Keyboard::Key::D, sf::milliseconds(200)))
    {
        // Change volume of audio
        if(getSelectMenuOptions() == SettingsMenuOptions::AUDIO)
        {
            setVloumeAudio(getVloumeAudio()-5);
            m_menuOptions.at(SettingsMenuOptions::AUDIO).setString("1.   Audio   " + std::to_string(getVloumeAudio()) +'%');     // Update text in menu.
        }
        if(getSelectMenuOptions() == SettingsMenuOptions::RESOLUTION)
        {
            setSelectResolution(getSelectResolution()-1);
            // Update text in menu.
            m_menuOptions.at(SettingsMenuOptions::RESOLUTION).setString("2.   Resolution  " + std::to_string(m_availabeResolution.at(getSelectResolution()).width) + 'x'
                                            + std::to_string(m_availabeResolution.at(getSelectResolution()).height)
                                            + ' ' + std::to_string(m_availabeResolution.at(getSelectResolution()).bitsPerPixel) + "Bit");
        }
    }
    if(holdKay(sf::Keyboard::Key::Right, sf::milliseconds(200)) || holdKay(sf::Keyboard::Key::A, sf::milliseconds(200)))
    {
        // Change volume of audio
        if(getSelectMenuOptions() == SettingsMenuOptions::AUDIO)
        {
            setVloumeAudio(getVloumeAudio()+5);
            m_menuOptions.at(SettingsMenuOptions::AUDIO).setString("1.   Audio   " + std::to_string(getVloumeAudio()) +'%');     // Update text in menu.
        }
        if(getSelectMenuOptions() == SettingsMenuOptions::RESOLUTION)
        {
            setSelectResolution(getSelectResolution()+1);
            // Update text in menu.
            m_menuOptions.at(SettingsMenuOptions::RESOLUTION).setString("2.   Resolution  " + std::to_string(m_availabeResolution.at(getSelectResolution()).width) + 'x'
                                            + std::to_string(m_availabeResolution.at(getSelectResolution()).height)
                                            + ' ' + std::to_string(m_availabeResolution.at(getSelectResolution()).bitsPerPixel) + "Bit");
        }
    }

        // If pressed Enter. Change view on next view.
    if(pressedKey(sf::Keyboard::Enter))
    {
        switch (getSelectMenuOptions()) {
        case SettingsMenuOptions::AUDIO:
            break;
        case SettingsMenuOptions::APPLY:
            accessWindow().create(sf::VideoMode(m_availabeResolution.at(getSelectResolution()).width, m_availabeResolution.at(getSelectResolution()).height
                                  , m_availabeResolution.at(getSelectResolution()).bitsPerPixel), "Pong", sf::Style::Fullscreen);
            break;
        case SettingsMenuOptions::RBACK:
            setDisplayNextView(SettingsMenu::GraphicView::MENU);
            break;
        default:
            break;
        }
    }
    //------------------------------------------------------------------------
}

SettingsMenu::GraphicView SettingsMenu::updateView()
{
    setDisplayNextView(SettingsMenu::GraphicView::SETTINGS);        // Reset next view for display.
    handleInputKeyboard();                                          // Handling all inputs.
    setMenuTextPosition();                                          // Update positions of all text in menu.
    updateMenuTextLook();                                           // Update look all text in menu.
    accessWindow().draw(*this);                                     // Draw all element witch this view on window.
    return getDisplayNextView();                                    // return next view for display.
}

