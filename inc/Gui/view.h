#ifndef VIEW_H
#define VIEW_H
#include <SFML/Graphics.hpp>
#include "Gui/text.h"
/*!
 * \brief The View class inherit from <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php">sf::Drawable</a>.
 * It is the base to others class for display selected scene of game.
 */
class View : public sf::Drawable
{
public:
    /*!
     * \brief The GraphicView enum
     */
    enum GraphicView
    {
        MENU        =   0,
        SETTINGS    =   1,
        GAME        =   2
    };

    /*!
     * \brief View is a default constructor.
     * \param window is a reference of graphic window, which display the View.
     */
    View(sf::RenderWindow &window);
    /*!
     * \brief Default virtual destructor.
     */
    virtual ~View();

    /*!
     * \brief updateView is the method for implementation in a target class.
     * You should use this method in order to update selected scene of game.
     */
    virtual GraphicView updateView()=0;



protected:
    /*!
     * \brief handleInputKeyboard is method for handling input witch a keyboard.
     */
    virtual void handleInputKeyboard();

    /*!
     * \brief pressedKey check a pres key of keyboard.
     * \param key is an enum <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php">sf::Keyboard::Key</a>.
     * \return return true if key is pres (change state with low to high), false otherwise.
     */
    bool pressedKey(const sf::Keyboard::Key key) const;

    /*!
     * \brief releasedKey check a release key of keyboard.
     * \param key is enum <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php">sf::Keyboard::Key</a>.
     * \return return true if key is release (change state with high to low), false otherwise.
     */
    bool releasedKey(const sf::Keyboard::Key key) const;

    /*!
     * \brief holdKay check a pres and hold key of keyboard.
     * \param key is an enum <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php">sf::Keyboard::Key</a>.
     * \param holdTime is a period after which return true.
     * \return return true if hold the pressed key for holdTime.
     */
    bool holdKay(const sf::Keyboard::Key key, sf::Time holdTime) const;

    /*!
     * \brief setSelectMenuOptions sets the selected position option in menu.
     * \param selectMenuOptions is value to be set as selected option in menu.
     */
    void setSelectMenuOptions(const int selectMenuOptions);

    /*!
     * \brief getSelectMenuOptions gets the selected position option in menu.
     * \return return value of selected position option in menu.
     */
    int getSelectMenuOptions() const;

    /*!
     * \brief setCountMenuOptions sets a quantity of display options in menu.
     * \param countMenuOptions value of quantity options.
     */
    void setCountMenuOptions(const int countMenuOptions);

    /*!
     * \brief getCountMenuOptions gets a quantity of display options in menu.
     * \return return value of quantity options.
     */
    int getCountMenuOptions() const;

    /*!
     * \brief setDisplayNextView sets an View for display on window in the next time.
     * \param view enum of GraphicView
     */
    void setDisplayNextView(const GraphicView view);

    /*!
     * \brief getDisplayNextView gets an View for display on window in the next time.
     * \return return enum of GraphicView
     */
    GraphicView getDisplayNextView() const;

    /*!
     * \brief accessWindow gets access to graphic window.
     * \return return reference on graphic window.
     */
    sf::RenderWindow &accessWindow();

    /*!
     * \brief setMenuTextPosition sets a positions of all text in menu.
     */
    void setMenuTextPosition();

    /*!
     * \brief updateMenuTextLook updates look of all text in menu.
     */
    void updateMenuTextLook();


protected:
    int m_countMenuOptions {0};                         //! Quantity of options in menu.
    Text m_title;                                       //! Object display title of view.
    std::vector<Text> m_menuOptions;                    //! Object display all options in menu.

private:
    int m_selectMenuOptions {0};                        //! Actual select option in display menu.
    sf::RenderWindow &m_window;                         //! Reference in graphic window.
    GraphicView m_displayNextView {GraphicView::MENU};  //! Select next view for display on window.
};

#endif // VIEW_H
