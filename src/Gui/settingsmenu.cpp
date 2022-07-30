#include "Gui/settingsmenu.h"
#include <iostream>

SettingsMenu::SettingsMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 2;              // Quantity menu options for display on this view.

    // Clear vector of the text, create new text and add this text for the vector.
    m_menuOptions.clear();
    for(int i = 0; i < quantityMenuOptions; i++)
    {
        Text *tempText_ptr = new Text;
        m_menuOptions.push_back(*tempText_ptr);
//        delete tempText_ptr;      // I don't know why this don't work.
    }
    this->setCountMenuOptions(quantityMenuOptions);             // Sets quantity menu options for display on this view.
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
    m_menuOptions.at(0).setString("1.   AUDIO   " + std::to_string(m_audio) +'%');
    m_menuOptions.at(1).setString("2.   BACK");

}

void SettingsMenu::handleInputKeyboard()    // Check inputs for general view.
{
    // If window is actual use (isn't minimized or active). It check inputs.
    if(!accessWindow().hasFocus())
        return;
    View::handleInputKeyboard();

    // Check input special input for this view.
    //-----------------------------------------------------------------------
        // If pressed Enter. Change view on next view.
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

