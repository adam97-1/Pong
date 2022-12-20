#ifndef LANMENU_H
#define LANMENU_H

#include "view.h"

/*!
 * \brief The LanMenu class inherits from View.
 * This class contains all elements for display on main menu.
 */
class LanMenu : public View
{
public:
    LanMenu(sf::RenderWindow & window);
    ~LanMenu();

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
        CreateHost = 0,
        ConnectToHost,
        Back
    };
    /*!
     * \brief setTextString sets all string for display.
     */
    void setTextString();
};

#endif // LANMENU_H
