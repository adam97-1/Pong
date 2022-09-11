#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <Gui/view.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include "rectangleobject.h"
#include "gamebounds.h"
#include "player.h"


/*!
 * \brief The GameView class inherits from View and SettingsEventListeners.
 * This class contains all elements for display on game view.
 */
class GameView : public View
{
public:
    /*!
     * \brief GameView is a default constructor. It Creates and sets all text in the view.
     * \param window is a reference of graphic window, which display this view.
     */
    GameView(sf::RenderWindow & window);

    /*!
     * \brief updateView get all inputs, update look and draw all object for display.
     * \return return enum for display next view.
     */
    virtual GraphicView updateView();

    /*!
     * \brief updateGame update all elements of this game view.
     */
    void updateGame();

    /*!
     * \brief updateDletaTime updates difference of time in game.
     */
    void updateDletaTime();

    /*!
     * \brief resetGame reset all elements of this game view.
     */
    void resetGame();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /*!
     * \brief handleInputKeyboard gets and handles all inputs.
     */
    void handleInputKeyboard();

private:

    /*!
     * \brief updateBall updates ball.
     */
    void updateBall();

    /*!
     * \brief updatePlayers update players.
     */
    void updatePlayers();

    /*!
     * \brief detectCollision detect all collision in game.
     */
    void detectCollision();

    /*!
     * \brief onSettingsChangeResolution its handle change resolution.
     * \param videoMode is actual resolution.
     */
    void onSettingsChangeResolution(sf::VideoMode videoMode);

    GameBounds m_boundsGame;            //! Bounds of game.
    std::vector<Player> m_players;      //! Players
    RectangleObject m_ball;             //! Ball
    sf::Clock m_clock;                  //! Clock
    sf::Time m_deltaTime;               //! DeltaTime
};

#endif // GAMEVIEW_H
