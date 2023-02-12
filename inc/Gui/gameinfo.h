#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <SFML/Graphics.hpp>
#include "Gui/view.h"


/*!
 * \brief The GameInfo class inherits from View.
 * This class contains all elements for display on game info view.
 */
class GameInfo : public View
{
public:
    /*!
     * \brief GameInfo is a default constructor. It Creates and sets all text in the view.
     * \param window is a reference of graphic window, which display this view.
     */
    GameInfo(sf::RenderWindow & window);

    /*!
     * \brief updateView gets all inputs, update look and draw all object for display.
     * \return return enum for display next view.
     */
    GraphicView updateView();
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /*!
     * \brief handleInputKeyboard gets and handles all inputs.
     */
    void handleInputKeyboard();
    void onSettingsChangeResolution(sf::VideoMode videoMode);
private:
    /*!
     * \brief The MainMenuOptions enum of available view.
     */
    enum GameInfoOptions
    {
        InfoPlayer1,
        InfoPlayer2,
        InfoBack
    };

    /*!
     * \brief setTextString sets all string for display.
     */
    void setTextString();
    /*!
     * \brief setMenuTextPosition sets all tests position on window.
     */
    void setMenuTextPosition();
};

#endif // GAMEINFO_H
