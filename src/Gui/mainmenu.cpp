#include "Gui/mainmenu.h"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 5;              // Quantity menu options for display on this view.

    // Clear vector of the text, create new text and add this text into the vector.
    Text *tempText_ptr = NULL;
    m_menuOptions.clear();
    for(int i = 0; i < quantityMenuOptions; i++)
    {
        tempText_ptr = new Text;
        m_menuOptions.push_back(*tempText_ptr);
//        delete tempText_ptr;      // I don't know why this doesn't work.
    }
    this->setCountMenuOptions(quantityMenuOptions);     // Sets quantity menu options for display on this view.
    setTextString();                                    // Sets strings for text in the view.
    updateMenuTextLook();
    setDisplayNextView(MainMenu::GraphicView::MainMenu);    // Sets default next view for display.

}

MainMenu::~MainMenu()
{
}


void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates) const
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
        m_audioSelectOption.play();
        // Check selected options and change view for corresponding next view.
        switch (getSelectMenuOptions()) {
        case MainMenuOptions::Player1:
            setDisplayNextView(MainMenu::GraphicView::GamePlayer1);
            break;
        case MainMenuOptions::Player2:
            setDisplayNextView(MainMenu::GraphicView::GamePlayer2);
            break;
        case MainMenuOptions::Settings:
            setDisplayNextView(MainMenu::GraphicView::SettingsMenu);
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
    setDisplayNextView(MainMenu::GraphicView::MainMenu);        // Reset next view for display.
    handleInputKeyboard();                                  // Handling all inputs.
    accessWindow().draw(*this);                             // Draw all elements from this view on the window.
    return getDisplayNextView();                            // return next view for display.
}


