#ifndef GRAPHICINTERFACE_H
#define GRAPHICINTERFACE_H

#include <SFML/Graphics.hpp>
#include "Gui/mainmenu.h"
#include "Gui/settingsmenu.h"
#include "settingseventlisteners.h"
#include "Gui/gameview.h"



/*!
 * \brief The GraphicInteface is the main graphic class.
 */
class GraphicInteface : public SettingsEventListeners
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
     * \brief setDisplayView sets a View for display on window.
     * \param view enum of GraphicView
     */
    void setDisplayView(const View::GraphicView view);

    /*!
     * \brief getDisplayNextView gets a View for display on window.
     * \return return enum of GraphicView
     */
    View::GraphicView getDisplayView() const;

private:
    sf::RenderWindow m_window;                                      //! Graphic window.
    MainMenu m_mainMenu {m_window};                                 //! Main menu view.
    GameView m_gameView {m_window};                                 //! Game view.
    SettingsMenu m_settingsMenu {m_window};                         //! Settings menu view.
    GameView m_gameView {m_window};
    View::GraphicView m_displayView {View::GraphicView::MENU};      //! Display view.

    /*!
     * \brief onSettingsChangeResolution its handle change resolution.
     * \param videoMode is actual resolution.
     */
    void onSettingsChangeResolution(sf::VideoMode resolution);

};

#endif // GRAPHICINTERFACE_H
