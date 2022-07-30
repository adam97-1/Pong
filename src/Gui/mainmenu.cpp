#include "Gui/mainmenu.h"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 5;              // Quantity menu options for display on this view.

    // Clear vector of the text, create new text and add this text for the vector.
    m_menuOptions.clear();
    for(int i = 0; i < quantityMenuOptions; i++)
    {
        Text *tempText_ptr = new Text;
        m_menuOptions.push_back(*tempText_ptr);
//        delete tempText_ptr;      // I don't know why this don't work.
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
    // Draw all elements for display.
    target.draw(m_title);
    for(const auto & text : m_menuOptions)
        target.draw(text);
}

void MainMenu::handleInputKeyboard()
{
    // If window is actual use (isn't minimized or active). It check inputs.
    if(!accessWindow().hasFocus())
        return;

    View::handleInputKeyboard();    // Check inputs for general view.

    // Check input special input for this view.
    //-----------------------------------------------------------------------
        // If pressed Enter. Change view on next view.
    if(pressedKey(sf::Keyboard::Enter))
    {
        // Check selected options and change view on corresponding next view.
        switch (getSelectMenuOptions()) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            setDisplayNextView(MainMenu::GraphicView::SETTINGS);
            break;
        case 4:
            // If chose Exit. Close Game.
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
    m_menuOptions.at(0).setString("1.   1 PLAYER");
    m_menuOptions.at(1).setString("2.   2 PLAYER");
    m_menuOptions.at(2).setString("3.   SETTINGS");
    m_menuOptions.at(3).setString("4.   GAME INFO");
    m_menuOptions.at(4).setString("5.   EXIT");
}

MainMenu::GraphicView MainMenu::updateView()
{
    setDisplayNextView(MainMenu::GraphicView::MENU);        // Reset next view for display.
    handleInputKeyboard();                                  // Handling all inputs.
    setMenuTextPosition();                                  // Update positions of all text in menu.
    updateMenuTextLook();                                   // Update look all text in menu.
    accessWindow().draw(*this);                             // Draw all element witch this view on window.
    return getDisplayNextView();                            // return next view for display.
}


