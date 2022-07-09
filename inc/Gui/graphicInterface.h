#ifndef GRAPHICINTERFACE_H
#define GRAPHICINTERFACE_H

#include <SFML/Graphics.hpp>

/*!
 * \brief The GraphicInteface is the main graphic class.
 */
class GraphicInteface
{
public:
    /*!
     * \brief void GraphicInteface( void ) create main window.
     *
     * Default parameter of window:
     *      - Wight: 800px
     *      - Height: 600px
     *      - WindowMode: FullScreen
     *      - BeatsPerPixel: 32
     */
    GraphicInteface();

    /*!
     * \brief accessWindow give access to window methods
     *
     * You can read about <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderWindow.php">sf::RenderWindow</a>.
     * \return Reference to window.
     */
    sf::RenderWindow & accessWindow();

private:
    sf::RenderWindow m_window; //! Main window.
};

#endif // GRAPHICINTERFACE_H
