#include "Gui/player2menu.h"

Player2Menu::Player2Menu(sf::RenderWindow & window) : View{window}
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
    this->setCountMenuOptions(quantityMenuOptions);     // Sets quantity menu options for display on this view.
    setTextString();                                    // Sets strings for text in the view.
    updateMenuTextLook();
    setDisplayNextView(Player2Menu::GraphicView::Player2Menu);    // Sets default next view for display.
}

Player2Menu::~Player2Menu()
{

}

View::GraphicView Player2Menu::updateView()
{
    setDisplayNextView(Player2Menu::GraphicView::Player2Menu);        // Reset next view for display.
    handleInputKeyboard();                                  // Handling all inputs.
    accessWindow().draw(*this);                             // Draw all elements from this view on the window.
    return getDisplayNextView();                            // return next view for display.
}

void Player2Menu::setTextString()
{
    m_title.setString("Player 2 options");
    m_menuOptions.at(MainMenuOptions::Offline).setString("1.   Offline");
    m_menuOptions.at(MainMenuOptions::Online).setString("2.   Online");
    m_menuOptions.at(MainMenuOptions::LAN).setString("3.   LAN");
    m_menuOptions.at(MainMenuOptions::Back).setString("4.   Back");
}

void Player2Menu::handleInputKeyboard()
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
        case MainMenuOptions::Offline:
            setDisplayNextView(Player2Menu::GraphicView::GameOffline);
            break;
        case MainMenuOptions::Online:
//            setDisplayNextView(Player2Menu::GraphicView::MainMenu);
            break;
        case MainMenuOptions::LAN:
//            setDisplayNextView(Player2Menu::GraphicView::MainMenu);
            break;
        case MainMenuOptions::Back:
            setDisplayNextView(Player2Menu::GraphicView::MainMenu);
            break;
        default:
            break;
        }
    }
    //------------------------------------------------------------------------
}

void Player2Menu::draw(sf::RenderTarget &target, sf::RenderStates) const
{
     // Display all elements.
    target.draw(m_title);
    for(const auto & text : m_menuOptions)
        target.draw(text);
}
