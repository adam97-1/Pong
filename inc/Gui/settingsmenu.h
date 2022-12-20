#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <SFML/Graphics.hpp>
#include "Gui/view.h"

#define _emit(x) for (uint8_t i = 0; i < m_listeners.size(); i++) m_listeners.at(i)->x

/*!
 * \brief The SettingsMenu class inherits from View.
 * This class contains all elements for display on main menu.
 */
class SettingsMenu : public View
{
public:
    /*!
     * \brief SettingsMenu is a default constructor. It Creates and sets all text in the view.
     * \param window is a reference of graphic window, which display this view.
     */
    SettingsMenu(sf::RenderWindow & window);

    /*!
     * \brief updateView gets all inputs, updates look and draw all object for display.
     * \return return enum for display next view.
     */
    GraphicView updateView();

    /*!
     * \brief addEventListener adds object to handle events from class inherits SettingsEventListeners.
     * \param listener is pointer to object inherits SettingsEventListeners.
     */
    void addEventListener(SettingsEventListeners * listener);

    /*!
     * \brief removeEventListener removes object to handle events from class inherits SettingsEventListeners.
     * \param listener is pointer to object inherits SettingsEventListeners.
     */
    void removeEventListener(SettingsEventListeners * listener);

    /*!
     * \brief sendAllSiganl sends all signals.
     */
    void sendAllSiganl();

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
     * \brief setVolumeAudio sets volume of sounds.
     * \param volume is volume of sounds.
     */
    void setVolumeAudio(int volume);
    /*!
     * \brief getVolumeAudio gets value of sound's volume.
     * \return return volume of sounds.
     */
    int getVolumeAudio();

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

    /*!
     * \brief getActualResorution check actual resolution and return index of availableResolution.
     * \return return index of availableResolution. If this resolution isn't into availableResolution.
     * Return -1 and print warning on console.
     */
    int getActualResorution();

    /*!
     * \brief checkAvailableResolution if monitors supported then It adds resolution for availableResolution.
     */
    void checkAvailableResolution();

    int m_audio {100};                                      //! Volume of sounds.
    std::vector<sf::VideoMode> m_availabeResolution;        //! Stores all supported resolutions of monitor.
    std::vector<std::string>   m_proportionsOfResolution;   //! Proportions of resolution
    int m_selectResolution {0};                             //! Select resolution.
    std::vector<SettingsEventListeners*> m_listeners;       //! Vector of listeners.
};


#endif // SETTINGSMENU_H
