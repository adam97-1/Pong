#include "Gui/graphicInterface.h"

GraphicInteface::GraphicInteface()
{
    m_settingsMenu.addEventListener(this);
    m_settingsMenu.addEventListener(&m_gameView);
    m_settingsMenu.addEventListener(&m_mainMenu);
    m_settingsMenu.addEventListener(&m_settingsMenu);
    m_settingsMenu.addEventListener(&m_player2Menu);
    m_settingsMenu.addEventListener(&m_lanMenu);
    m_settingsMenu.sendAllSiganl();
}

sf::RenderWindow & GraphicInteface::accessWindow()
{
    return m_window;
}

void GraphicInteface::updateGraphic()
{
    // Hidden all display element and sets background color of window on back.
    m_window.clear(sf::Color::Black);
    m_gameView.updateDletaTime();

    // Check view for display and display it.
    switch (getDisplayView()) {
    case View::GraphicView::MainMenu:
        setDisplayView(m_mainMenu.updateView());
        m_gameView.resetGame();
        break;
    case View::GraphicView::SettingsMenu:
        setDisplayView(m_settingsMenu.updateView());
        break;
    case View::GraphicView::Player2Menu:
        setDisplayView(m_player2Menu.updateView());
        break;
    case View::GraphicView::GamePlayer1:
        m_gameView.setAiPlayer(true);
        m_gameView.setDisplayNextView(GameView::GraphicView::GamePlayer1);
        setDisplayView(m_gameView.updateView());
        break;
    case View::GraphicView::GameOffline:
        m_gameView.setAiPlayer(false);
        m_gameView.setDisplayNextView(GameView::GraphicView::GameOffline);
        setDisplayView(m_gameView.updateView());
        break;
    case View::GraphicView::LanMenu:
        setDisplayView(m_lanMenu.updateView());
        break;
    case View::GraphicView::CreateHost:
        setDisplayView(m_mainMenu.updateView());
        break;
    case View::GraphicView::ConnectToHost:
        setDisplayView(m_mainMenu.updateView());
        break;
    default:
        break;
    }

}

void GraphicInteface::setDisplayView(const View::GraphicView view)
{
    m_displayView = view;
}

View::GraphicView GraphicInteface::getDisplayView() const
{
    return m_displayView;
}

void GraphicInteface::onSettingsChangeResolution(sf::VideoMode videoMode)
{
    m_window.create(videoMode, "Pong", sf::Style::Default);
    m_window.setFramerateLimit(60);
}

