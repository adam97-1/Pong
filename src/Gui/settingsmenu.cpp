#include "Gui/settingsmenu.h"
#include <iostream>
#include <assert.h>


SettingsMenu::SettingsMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 4;              // Quantity menu options for display on this view.

    // Clear vector of the text, create new text and add this text into the vector.
    Text *tempText_ptr = NULL;
    m_menuOptions.clear();
    for(int i = 0; i < quantityMenuOptions; i++)
    {
        tempText_ptr = new Text;
        m_menuOptions.push_back(*tempText_ptr);
//        delete tempText_ptr;      // I don't know why this doesn't work.
    }
    this->setCountMenuOptions(quantityMenuOptions);             // Sets quantity menu options for display on this view.
    m_availabeResolution = sf::VideoMode::getFullscreenModes();
    setTextString();
    updateMenuTextLook();                                       // Sets strings for text in the view.
    setDisplayNextView(SettingsMenu::GraphicView::SETTINGS);    // Sets default next view for display.
}

void SettingsMenu::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    // Display all elements.
    target.draw(m_title);
    for(const auto & text : m_menuOptions)
        target.draw(text);
}

void SettingsMenu::setTextString()
{
    m_title.setString("Settings");
    m_menuOptions.at(SettingsMenuOptions::AUDIO).setString("1.   Audio           " + std::to_string(getVloumeAudio()) +'%');
    m_menuOptions.at(SettingsMenuOptions::RESOLUTION).setString("2.   Resolution    " + std::to_string(m_availabeResolution.at(getSelectResolution()).width) + 'x'
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

int SettingsMenu::getActualResorution()
{
    int index = 0;
    sf::VideoMode actualResorution = sf::VideoMode::getDesktopMode();                 // Gets actual resolution.
    // Check if the actualResorution is into availableResolution. Then return index of this resolution.
    for(const auto &res : m_availabeResolution)
    {
        if(res == actualResorution)
            return index;
        index++;
    }
    // If actualResorution isn't into availableResolution. Then return -1 and print warning.
    std::cout << "This resolution isn't into vector of available resolution";
    return -1;
}

void SettingsMenu::handleInputKeyboard()
{
    // If window is active. It check inputs.
    if(!accessWindow().hasFocus())
        return;
    View::handleInputKeyboard();                // Check inputs for general view.

    // Check input special input for this view.
    //-----------------------------------------------------------------------
    if(holdKay(sf::Keyboard::Key::Left, sf::milliseconds(200)) || holdKay(sf::Keyboard::Key::D, sf::milliseconds(200)))
    {
        // Change volume of audio
        if(getSelectMenuOptions() == SettingsMenuOptions::AUDIO)
        {
            setVloumeAudio(getVloumeAudio()-5);
            setTextString();                                                // Update strings of all text in menu.
        }
        // Change resolution.
        if(getSelectMenuOptions() == SettingsMenuOptions::RESOLUTION)
        {
            setSelectResolution(getSelectResolution()-1);
            setTextString();                                                // Update strings of all text in menu.
        }
    }
    if(holdKay(sf::Keyboard::Key::Right, sf::milliseconds(200)) || holdKay(sf::Keyboard::Key::A, sf::milliseconds(200)))
    {
        // Change volume of audio
        if(getSelectMenuOptions() == SettingsMenuOptions::AUDIO)
        {
            setVloumeAudio(getVloumeAudio()+5);
            setTextString();                                                // Update strings of all text in menu.

        }
        // Change resolution.
        if(getSelectMenuOptions() == SettingsMenuOptions::RESOLUTION)
        {
            setSelectResolution(getSelectResolution()+1);
            setTextString();                                                // Update strings of all text in menu.

        }
    }

        // If pressed Enter. Change view on next view.
    if(pressedKey(sf::Keyboard::Enter))
    {
        switch (getSelectMenuOptions()) {
        case SettingsMenuOptions::AUDIO:
            break;
        case SettingsMenuOptions::APPLY:
            _emit(onSettingsChangeResolution(m_availabeResolution.at(getSelectResolution())));
            break;
        case SettingsMenuOptions::RBACK:
            setDisplayNextView(SettingsMenu::GraphicView::MENU);
            setSelectResolution(getActualResorution());
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
    accessWindow().draw(*this);                                     // Draw all element witch this view on window.
    return getDisplayNextView();                                    // return next view for display.
}

void SettingsMenu::addEventListener(SettingsEventListeners * listener){
    assert(listener);
    assert(std::find(m_listeners.begin(), m_listeners.end(), listener) == m_listeners.end());

    m_listeners.push_back(listener);
}

void SettingsMenu::removeEventListener(SettingsEventListeners * listener){
    assert(listener);
    std::vector<SettingsEventListeners*>::iterator it = std::find(m_listeners.begin(), m_listeners.end(), listener);

    if (it == m_listeners.end()) return;
    m_listeners.erase(it);
}

void SettingsMenu::sendAllSiganl()
{
    _emit(onSettingsChangeAudio(getVloumeAudio()));
    _emit(onSettingsChangeResolution(m_availabeResolution.at(getSelectResolution())));
}
