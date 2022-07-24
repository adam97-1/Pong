#include "Gui/graphicInterface.h"

GraphicInteface::GraphicInteface()
{
    constexpr unsigned int window_width = 800;
    constexpr unsigned int window_height = 600;

    m_window.create(sf::VideoMode(window_width, window_height), "Pong", sf::Style::Close);

}

sf::RenderWindow & GraphicInteface::accessWindow()
{
    return m_window;
}

void GraphicInteface::updateGraphic()
{
    m_window.clear(sf::Color::Black);
    m_mainMenu.updateView();
}
