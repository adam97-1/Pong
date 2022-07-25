#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <SFML/Graphics.hpp>
#include "Gui/view.h"


class SettingsMenu : public View
{
public:
    /*!
     * \brief SettingsMenu is a default constructor. It Creates and stets all text in the view.
     * \param window is a reference of graphic window, which display this view.
     */
    SettingsMenu(sf::RenderWindow & window);

    /*!
     * \brief updateView gets all inputs, update look and draw all object for display.
     * \return return enum for display next view.
     */
    GraphicView updateView();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /*!
     * \brief handleInputKeyboard gets and handling all inputs.
     */
    void handleInputKeyboard();

private:
    /*!
     * \brief setTextString sets all string for display text.
     */
    void setTextString();

    unsigned int m_audio {100};     //! Volume of sounds
};

#endif // SETTINGSMENU_H
