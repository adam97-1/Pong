#include "Gui/mainmenu.h"

MainMenu::MainMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 5;
    m_menuOptions.clear();
    for(int i = 0; i<quantityMenuOptions; i++)
    {
        m_menuOptions.push_back(*new Text());
    }
    this->setCountMenuOptions(quantityMenuOptions);
    setTextString();

}

MainMenu::~MainMenu()
{
    for(auto & text : m_menuOptions)
        delete &text;
}

void MainMenu::updateView()
{
    handleInputKeyboard();
    setTextPosition();
    accessWindow().draw(*this);
}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_title);
    for(const auto & text : m_menuOptions)
        target.draw(text);
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

void MainMenu::setTextPosition()
{
    sf::Vector2u windowSize = accessWindow().getSize();
    sf::FloatRect rectTitle = m_title.getLocalBounds();
    m_title.setOrigin(rectTitle.width/2, rectTitle.top);
    m_title.setPosition(windowSize.x/2, windowSize.y/10);

    int maxWidthText = 0;
    for(const auto & text : m_menuOptions)
    {
        sf::FloatRect rectText = text.getLocalBounds();
        if(maxWidthText < rectText.width)
            maxWidthText = rectText.width;
    }

    int index = 0;
    for(auto & text : m_menuOptions)
    {
        text.setPosition((windowSize.x - maxWidthText)/2, windowSize.y/10+index*text.getCharacterSize()*1.5+50);
        index++;
    }
}
