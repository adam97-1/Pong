#include "Gui/mainmenu.h"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityMenuOptions = 5;
    m_menuOptions.clear();
    for(int i = 0; i < quantityMenuOptions; i++)
    {
        Text *tempText_ptr = new Text;
        m_menuOptions.push_back(*tempText_ptr);
//        delete tempText_ptr;
    }
    this->setCountMenuOptions(quantityMenuOptions);
    setTextString();
    setDisplayNextView(MainMenu::GraphicView::MENU);

}

MainMenu::~MainMenu()
{
//    for(auto & text : m_menuOptions)
//        delete &text;
}


void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_title);
    for(const auto & text : m_menuOptions)
        target.draw(text);
}

void MainMenu::handleInputKeyboard()
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
            break;
        case 2:
            setDisplayNextView(MainMenu::GraphicView::SETTINGS);
            break;
        case 4:
            accessWindow().close();
        default:
            break;
        }
    }
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
    setDisplayNextView(MainMenu::GraphicView::MENU);
    handleInputKeyboard();
    setMenuTextPosition();
    updateMenuTextLook();
    accessWindow().draw(*this);
    return getDisplayNextView();
}


