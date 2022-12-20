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
    checkAvailableResolution();
    setTextString();
    updateMenuTextLook();                                       // Sets strings for text in the view.
    setDisplayNextView(SettingsMenu::GraphicView::SettingsMenu);    // Sets default next view for display.
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
    m_menuOptions.at(SettingsMenuOptions::AUDIO).setString("1.   Audio           " + std::to_string(getVolumeAudio()) +'%');
    m_menuOptions.at(SettingsMenuOptions::RESOLUTION).setString("2.   Resolution    " + std::to_string(m_availabeResolution.at(getSelectResolution()).width) + 'x'
                                    + std::to_string(m_availabeResolution.at(getSelectResolution()).height)
                                    + " " + m_proportionsOfResolution.at(getSelectResolution()));
    m_menuOptions.at(SettingsMenuOptions::APPLY).setString("4.   Apply");
    m_menuOptions.at(SettingsMenuOptions::RBACK).setString("5.   Back");

}

void SettingsMenu::setVolumeAudio(int volume)
{
    if(volume > 100)
        m_audio = 100;
    else if(volume < 0)
        m_audio = 0;
    else
        m_audio = volume;
}

int SettingsMenu::getVolumeAudio()
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

void SettingsMenu::checkAvailableResolution()
{
    const std::string proportions[] = {"4:3", "16:9", "16:10"};
    const unsigned int resolutionWidth[3][8] = {{640, 800, 1024, 1280, 1600, 2048, 0, },
                                          {1280, 1366, 1024, 1600, 1920, 2048, 2560, 4096},
                                          {1280, 1440, 1600, 1680, 1920, 2560, 0, 0}};
    const unsigned int resolutionHeight[3][8] = {{480, 600, 768, 1050, 1200, 1536, 0, },
                                          {720, 768, 600, 900, 1080, 1152, 1440, 2304},
                                          {800, 900, 1024, 1050, 1200, 1600, 0, 0}};
    sf::VideoMode* videoMode = NULL;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 8; j++)
        {
            videoMode = new sf::VideoMode(resolutionWidth[i][j], resolutionHeight[i][j]);
            if(videoMode == NULL)
            {
                std::cout << "void SettingsMenu::checkAvailableResoluution(): Don't create sf::VideoMode" << std::endl;
            }
            if(videoMode->isValid())
            {
                m_availabeResolution.push_back(*videoMode);
                m_proportionsOfResolution.push_back(proportions[i]);
            }
            delete videoMode;
        }
    setSelectResolution(getActualResorution());
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
        m_audioSelectOption.play();
        // Change volume of audio
        if(getSelectMenuOptions() == SettingsMenuOptions::AUDIO)
        {
            setVolumeAudio(getVolumeAudio()-5);
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
        m_audioSelectOption.play();

        // Change volume of audio
        if(getSelectMenuOptions() == SettingsMenuOptions::AUDIO)
        {
            setVolumeAudio(getVolumeAudio()+5);
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
        m_audioSelectOption.play();
        switch (getSelectMenuOptions()) {
        case SettingsMenuOptions::AUDIO:
            break;
        case SettingsMenuOptions::APPLY:
            _emit(onSettingsChangeResolution(m_availabeResolution.at(getSelectResolution())));
            _emit(onSettingsChangeAudio(getVolumeAudio()));
            break;
        case SettingsMenuOptions::RBACK:
            setDisplayNextView(SettingsMenu::GraphicView::MainMenu);
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
    setDisplayNextView(SettingsMenu::GraphicView::SettingsMenu);        // Reset next view for display.
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
    _emit(onSettingsChangeAudio(getVolumeAudio()));
    _emit(onSettingsChangeResolution(m_availabeResolution.at(getSelectResolution())));
}
