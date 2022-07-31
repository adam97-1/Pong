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
     * \brief The SettingsMenuOptions enum of options in menu.
     */
    enum SettingsMenuOptions
    {
        AUDIO = 0,
        RESOLUTION,
        APPLY,
        RBACK
    };

    /*!
     * \brief setTextString sets all string for display text.
     */
    void setTextString();

    /*!
     * \brief setVloumeAudio sets volume of sounds.
     * \param volume is volume of sounds.
     */
    void setVloumeAudio(int volume);
    /*!
     * \brief getVloumeAudio gets value if volume sounds.
     * \return return volume of sounds.
     */
    int getVloumeAudio();

    /*!
     * \brief setSelectResolution sets index of available resolution for display.
     * \param select is a index of available resolutions.
     */
    void setSelectResolution(int select);

    /*!
     * \brief getSelectResolution gets index of available resolution for display.
     * \return return index of selected resolution.
     */
    int getSelectResolution();

    int m_audio {100};                                  //! Volume of sounds.
    std::vector<sf::VideoMode> m_availabeResolution;    //! Stored all support resolution of monitor.
    int m_selectResolution {0};                         //! Selected resolution.
};

#endif // SETTINGSMENU_H
