#include "Gui/graphicInterface.h"

GraphicInteface::GraphicInteface()
{
    constexpr unsigned int window_width = 800;
    constexpr unsigned int window_height = 600;

        m_window.create(sf::VideoMode(window_width, window_height), "Pong");

}

sf::RenderWindow & GraphicInteface::accessWindow()
{
    return m_window;
}

void GraphicInteface::updateGraphic()
{

}
