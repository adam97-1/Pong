#include "Gui/graphicInterface.h"

GraphicInteface::GraphicInteface()
{
    m_settingsMenu.addEventListener(this);
    m_settingsMenu.addEventListener(&m_gameView);
    m_settingsMenu.addEventListener(&m_mainMenu);
    m_settingsMenu.addEventListener(&m_settingsMenu);
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
    case View::GraphicView::MENU:
        setDisplayView(m_mainMenu.updateView());
        m_gameView.resetGame();
        break;
    case View::GraphicView::SETTINGS:
        setDisplayView(m_settingsMenu.updateView());
        break;
    case View::GraphicView::Player2:
        setDisplayView(m_gameView.updateView());
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
    m_window.create(videoMode, "Pong", sf::Style::Fullscreen);
    m_window.setFramerateLimit(60);
}

