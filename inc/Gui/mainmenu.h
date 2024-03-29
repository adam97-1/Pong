#ifndef MAINMENU_H
#define MAINMENU_H

#include <vector>
#include <Gui/view.h>
#include <Gui/text.h>

/*!
 * \brief The MainMenu class inherits from View.
 * This class contains all elements for display on main menu.
 */
class MainMenu : public View
{
public:
    /*!
     * \brief MainMenu is a default constructor. It Creates and sets all text in the view.
     * \param window is a reference of graphic window, which display this view.
     */
    MainMenu(sf::RenderWindow & window);
    ~MainMenu();

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
        Player1 = 0,
        Player2,
        Settings,
        GameInfo,
        Exit
    };
    /*!
     * \brief setTextString sets all string for display.
     */
    void setTextString();




};

#endif // MAINMENU_H
