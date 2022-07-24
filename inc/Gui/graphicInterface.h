#ifndef GRAPHICINTERFACE_H
#define GRAPHICINTERFACE_H

#include <SFML/Graphics.hpp>
#include "Gui/mainmenu.h"



/*!
 * \brief The GraphicInteface is the main graphic class.
 */
class GraphicInteface
{
public:

    /*!
     * \brief The GraphicView enum
     */
    enum GraphicView
    {
        MENU        =   0,
        SETTINGS    =   1,
        GAME        =   2
    };

    /*!
     * \brief GraphicInteface create main window.
     *
     * Default parameter of window:
     *      - Wight: 800pix
     *      - Height: 600pix
     *      - BeatsPerPixel: 32
     *      - Window name: Pong
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

private:
    sf::RenderWindow m_window; //! Main window.
    MainMenu m_mainMenu {m_window};

};

#endif // GRAPHICINTERFACE_H
