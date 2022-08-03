#include "Gui/graphicInterface.h"

GraphicInteface::GraphicInteface()
{

}

sf::RenderWindow & GraphicInteface::accessWindow()
{
    return m_window;
}

void GraphicInteface::updateGraphic()
{
    // Hidden all display element and sets background color of window on back.
    m_window.clear(sf::Color::Black);

    // Check view for display and display it.
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
