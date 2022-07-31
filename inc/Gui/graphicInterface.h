#ifndef GRAPHICINTERFACE_H
#define GRAPHICINTERFACE_H

#include <SFML/Graphics.hpp>
#include "Gui/mainmenu.h"
#include "Gui/settingsmenu.h"



/*!
 * \brief The GraphicInteface is the main graphic class.
 */
class GraphicInteface
{
public:
    /*!
     * \brief GraphicInteface is a default constructor.
     */
    GraphicInteface();

    /*!
     * \brief accessWindow give access to window methods
     *
     * You can read about <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php">sf::RenderWindow</a>.
     * \return Reference to window.
     */
    sf::RenderWindow & accessWindow();

    /*!
     * \brief updateGraphic select view to display and call virtual method updateView for select view.
     */
    void updateGraphic();

    /*!
     * \brief setDisplayView sets an View for display on window.
     * \param view enum of GraphicView
     */
    void setDisplayView(const View::GraphicView view);

    /*!
     * \brief getDisplayNextView gets an View for display on window.
     * \return return enum of GraphicView
     */
    View::GraphicView getDisplayView() const;

private:
    sf::RenderWindow m_window;                                      //! Graphic window.
    MainMenu m_mainMenu {m_window};                                 //! Main menu view.
    SettingsMenu m_settingsMenu {m_window};                         //! Settings menu view.
    View::GraphicView m_displayView {View::GraphicView::MENU};      //! Display view.

};

#endif // GRAPHICINTERFACE_H
