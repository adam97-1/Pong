#include "Gui/mainmenu.h"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 5;              // Quantity menu options for display on this view.

    // Clear vector of the text, create new text and add this text into the vector.
    m_menuOptions.clear();
    for(int i = 0; i < quantityMenuOptions; i++)
    {
        Text *tempText_ptr = new Text;
        m_menuOptions.push_back(*tempText_ptr);
//        delete tempText_ptr;      // I don't know why this doesn't work.
    }
    this->setCountMenuOptions(quantityMenuOptions);     // Sets quantity menu options for display on this view.
    setTextString();                                    // Sets strings for text in the view.
    setDisplayNextView(MainMenu::GraphicView::MENU);    // Sets default next view for display.

}

MainMenu::~MainMenu()
{
}


void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Display all elements.
    target.draw(m_title);
    for(const auto & text : m_menuOptions)
        target.draw(text);
}

void MainMenu::handleInputKeyboard()
{
    // If window is active. It check inputs.
    if(!accessWindow().hasFocus())
        return;

    View::handleInputKeyboard();    // Check inputs for general view.

    // Check special input for this view.
    //-----------------------------------------------------------------------
        // If pressed Enter. Change view for next view.
    if(pressedKey(sf::Keyboard::Enter))
    {
        // Check selected options and change view for corresponding next view.
        switch (getSelectMenuOptions()) {
        case MainMenuOptions::Player1:
            break;
        case MainMenuOptions::Player2:
            setDisplayNextView(MainMenu::GraphicView::Player2);
            break;
        case MainMenuOptions::Settings:
            setDisplayNextView(MainMenu::GraphicView::SETTINGS);
            break;
        case MainMenuOptions::GameInfo:
            break;
        case MainMenuOptions::Exit:
            accessWindow().close();
        default:
            break;
        }
    }
    //------------------------------------------------------------------------
}

void MainMenu::setTextString()
{
    m_title.setString("Pong Game");
    m_menuOptions.at(MainMenuOptions::Player1).setString("1.   1 Player");
    m_menuOptions.at(MainMenuOptions::Player2).setString("2.   2 Player");
    m_menuOptions.at(MainMenuOptions::Settings).setString("3.   Settings");
    m_menuOptions.at(MainMenuOptions::GameInfo).setString("4.   Game info");
    m_menuOptions.at(MainMenuOptions::Exit).setString("5.   Exit");
}

MainMenu::GraphicView MainMenu::updateView()
{
    setDisplayNextView(MainMenu::GraphicView::MENU);        // Reset next view for display.
    handleInputKeyboard();                                  // Handling all inputs.
    setMenuTextPosition();                                  // Update positions of all text in menu.
    updateMenuTextLook();                                   // Update look of all text in menu.
    accessWindow().draw(*this);                             // Draw all elements from this view on the window.
    return getDisplayNextView();                            // return next view for display.
}


