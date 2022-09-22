#ifndef PLAYER2MENU_H
#define PLAYER2MENU_H

#include "Gui/view.h"

class Player2Menu : public View
{
public:
    /*!
     * \brief Player2Menu is a default constructor. It Creates and sets all text in the view.
     * \param window is a reference of graphic window, which display this view.
     */
    Player2Menu(sf::RenderWindow & window);
    ~Player2Menu();

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

private:

    /*!
     * \brief The MainMenuOptions enum of available view.
     */
    enum MainMenuOptions
    {
        Offline = 0,
        Online,
        LAN,
        Back
    };
    /*!
     * \brief setTextString sets all string for display.
     */
    void setTextString();
};

#endif // PLAYER2MENU_H
