#include "Gui/graphicInterface.h"

GraphicInteface::GraphicInteface()
{
    // Sets default resolution of window.
    constexpr unsigned int window_width = 800;
    constexpr unsigned int window_height = 600;

    // Create window witch name Pong.
    // Window isn't
    m_window.create(sf::VideoMode(window_width, window_height), "Pong", sf::Style::None);

}

sf::RenderWindow & GraphicInteface::accessWindow()
{
    return m_window;
}

void GraphicInteface::updateGraphic()
{
    m_window.clear(sf::Color::Black);
    switch (getDisplayView()) {
    case View::GraphicView::MENU:
        setDisplayView(m_mainMenu.updateView());
        break;
    case View::GraphicView::SETTINGS:
        setDisplayView(m_settingsMenu.updateView());
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
