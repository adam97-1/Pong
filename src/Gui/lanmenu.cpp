#include "Gui/lanmenu.h"

LanMenu::LanMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 2;              // Quantity menu options for display on this view.

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
    setDisplayNextView(LanMenu::GraphicView::LanMenu);    // Sets default next view for display.
}

LanMenu::~LanMenu()
{

}

LanMenu::GraphicView LanMenu::updateView()
{
    setDisplayNextView(LanMenu::GraphicView::LanMenu);        // Reset next view for display.
    handleInputKeyboard();                                  // Handling all inputs.
    accessWindow().draw(*this);                             // Draw all elements from this view on the window.
    return getDisplayNextView();                            // return next view for display.
}

void LanMenu::draw(sf::RenderTarget &target, sf::RenderStates) const
{
     // Display all elements.
    target.draw(m_title);
    for(const auto & text : m_menuOptions)
        target.draw(text);
}

void LanMenu::handleInputKeyboard()
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
            setDisplayNextView(LanMenu::GraphicView::CreateHost);
            break;
        case MainMenuOptions::ConnectToHost:
            setDisplayNextView(LanMenu::GraphicView::ConnectToHost);
            break;
        }
    }
    //------------------------------------------------------------------------
}

void LanMenu::setTextString()
{
    m_title.setString("LAN");
    m_menuOptions.at(MainMenuOptions::CreateHost).setString("1.   Create host");
    m_menuOptions.at(MainMenuOptions::ConnectToHost).setString("2.   Connect to host");

}
