#include "Gui/onlinemenu.h"

OnlineMenu::OnlineMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 3;              // Quantity menu options for display on this view.

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
    setDisplayNextView(OnlineMenu::GraphicView::OnlineMenu);    // Sets default next view for display.
}

OnlineMenu::~OnlineMenu()
{

}

OnlineMenu::GraphicView OnlineMenu::updateView()
{
    setDisplayNextView(OnlineMenu::GraphicView::OnlineMenu);        // Reset next view for display.
    handleInputKeyboard();                                  // Handling all inputs.
    accessWindow().draw(*this);                             // Draw all elements from this view on the window.
    return getDisplayNextView();                            // return next view for display.
}

void OnlineMenu::draw(sf::RenderTarget &target, sf::RenderStates) const
{
     // Display all elements.
    target.draw(m_title);
    for(const auto & text : m_menuOptions)
        target.draw(text);
}

void OnlineMenu::handleInputKeyboard()
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
        case MainMenuOptions::CreateHost:
            setDisplayNextView(OnlineMenu::GraphicView::CreateHost);
            break;
        case MainMenuOptions::ConnectToHost:
            setDisplayNextView(OnlineMenu::GraphicView::ConnectToHost);
            break;
        case MainMenuOptions::Back:
            setDisplayNextView(OnlineMenu::GraphicView::Player2Menu);
            break;
        }
    }
    //------------------------------------------------------------------------
}

void OnlineMenu::setTextString()
{
    m_title.setString("Online");
    m_menuOptions.at(MainMenuOptions::CreateHost).setString("1.   Create host");
    m_menuOptions.at(MainMenuOptions::ConnectToHost).setString("2.   Connect to host");
    m_menuOptions.at(MainMenuOptions::Back).setString("3.   Back");

}
