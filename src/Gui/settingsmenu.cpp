#include "Gui/settingsmenu.h"
#include <iostream>

SettingsMenu::SettingsMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 2;
    m_menuOptions.clear();
    for(int i = 0; i < quantityMenuOptions; i++)
    {
        Text *tempText_ptr = new Text;
        m_menuOptions.push_back(*tempText_ptr);
//        delete tempText_ptr;
    }
    this->setCountMenuOptions(quantityMenuOptions);
    setTextString();
    setDisplayNextView(SettingsMenu::GraphicView::SETTINGS);
}

void SettingsMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_title);
    for(const auto & text : m_menuOptions)
        target.draw(text);
}

void SettingsMenu::setTextString()
{
    m_title.setString("Settings");
    m_menuOptions.at(0).setString("1.   AUDIO   " + std::to_string(m_audio) +'%');
    m_menuOptions.at(1).setString("2.   BACK");

}

void SettingsMenu::handleInputKeyboard()
{
    if(!accessWindow().hasFocus())
        return;
    View::handleInputKeyboard();
    if(pressedKey(sf::Keyboard::Enter))
    {
        switch (getSelectMenuOptions()) {
        case 0:

            break;
        case 1:
            setDisplayNextView(SettingsMenu::GraphicView::MENU);
            break;
        default:
            break;
        }
    }
}

SettingsMenu::GraphicView SettingsMenu::updateView()
{
    setDisplayNextView(SettingsMenu::GraphicView::SETTINGS);
    handleInputKeyboard();
    setMenuTextPosition();
    updateMenuTextLook();
    accessWindow().draw(*this);
    return getDisplayNextView();
}

