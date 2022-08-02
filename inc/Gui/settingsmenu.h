#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <SFML/Graphics.hpp>
#include "Gui/view.h"


class SettingsMenu : public View
{
public:
    /*!
     * \brief SettingsMenu is a default constructor. It Creates and sets all text in the view.
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
     * \brief handleInputKeyboard gets and handles all inputs.
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
     * \brief setTextString sets all string for display.
     */
    void setTextString();

    /*!
     * \brief setVloumeAudio sets volume of sounds.
     * \param volume is volume of sounds.
     */
    void setVloumeAudio(int volume);
    /*!
     * \brief getVloumeAudio gets value of sound's volume.
     * \return return volume of sounds.
     */
    int getVloumeAudio();

    /*!
     * \brief setSelectResolution sets index of available resolutions for display.
     * \param select is an index of available resolutions.
     */
    void setSelectResolution(int select);

    /*!
     * \brief getSelectResolution gets index of available resolutions for display.
     * \return return index of selected resolutions.
     */
    int getSelectResolution();

    int m_audio {100};                                  //! Volume of sounds.
    std::vector<sf::VideoMode> m_availabeResolution;    //! Stores all supported resolutions of monitor.
    int m_selectResolution {0};                         //! Select resolution.
};

#endif // SETTINGSMENU_H
