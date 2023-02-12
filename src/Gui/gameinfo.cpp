#include "Gui/gameinfo.h"

GameInfo::GameInfo(sf::RenderWindow & window) : View{window}
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
//    updateMenuTextLook();
    setDisplayNextView(GameInfo::GraphicView::GameInfo);    // Sets default next view for display.
}

void GameInfo::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    // Display all elements.
   target.draw(m_title);
   for(const auto & text : m_menuOptions)
       target.draw(text);
}


void GameInfo::setTextString()
{
    m_title.setString("Game information");
    m_menuOptions.at(GameInfoOptions::InfoPlayer1).setString("Control Player 1:\nUp: Arrow Up\nDown: Arrow Down");
    m_menuOptions.at(GameInfoOptions::InfoPlayer2).setString("Control Player 2:\nUp: Arrow W\nDown: Arrow S");
    m_menuOptions.at(GameInfoOptions::InfoBack).setString("Return to menu: ESC");
}

void GameInfo::setMenuTextPosition()
{
    sf::Vector2u windowSize = accessWindow().getSize();     // Gets resolution of window.
    sf::FloatRect rectTitle = m_title.getLocalBounds();     // Gets size of m_title.
    m_title.setOrigin(rectTitle.width/2, rectTitle.top);    // Changes origin point of the title.
    m_title.setPosition(windowSize.x/2, windowSize.y/10);   // Sets title in the top-center position of the view.


//     Checks max width of all options text in menu.
    int maxWidthText = 0;
    for(const auto & text : m_menuOptions)
    {
        sf::FloatRect rectText = text.getLocalBounds();
        if(maxWidthText < rectText.width)
            maxWidthText = rectText.width;
    }

//     Set positions of all options text according to maxWidthText.

    m_menuOptions.at(GameInfoOptions::InfoPlayer2).setPosition(windowSize.x/20, windowSize.y/3);
    m_menuOptions.at(GameInfoOptions::InfoPlayer1).setPosition(windowSize.x - maxWidthText*1.1, windowSize.y/3);

    rectTitle = m_menuOptions.at(GameInfoOptions::InfoBack).getLocalBounds();
    m_menuOptions.at(GameInfoOptions::InfoBack).setOrigin(rectTitle.width/2, rectTitle.top);
    m_menuOptions.at(GameInfoOptions::InfoBack).setPosition(windowSize.x/2, windowSize.y/4);
}

void GameInfo::handleInputKeyboard()
{
    // If window is active. It check inputs.
    if(!accessWindow().hasFocus())
        return;

    // Check special input for this view.
    //-----------------------------------------------------------------------
        // If pressed Enter. Change view for next view.
    if(pressedKey(sf::Keyboard::Escape))
    {
        m_audioSelectOption.play();
        setDisplayNextView(GameInfo::GraphicView::MainMenu);
    }
}

View::GraphicView GameInfo::updateView()
{
    setDisplayNextView(GameInfo::GraphicView::GameInfo);        // Reset next view for display.
    handleInputKeyboard();                                  // Handling all inputs.
    accessWindow().draw(*this);                             // Draw all elements from this view on the window.
    return getDisplayNextView();                            // return next view for display.
}

void GameInfo::onSettingsChangeResolution(sf::VideoMode videoMode)
{
    m_title.setCharacterSize(videoMode.height/10);
    for(auto & text : m_menuOptions)
    {
        text.setCharacterSize(videoMode.height/20);       // Adapts size of text for actual resolution.
    }
    setMenuTextPosition();
}

