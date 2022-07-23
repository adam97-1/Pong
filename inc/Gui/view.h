#ifndef VIEW_H
#define VIEW_H
#include <SFML/Graphics.hpp>
/*!
 * \brief The View class inherit from <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Drawable.php">sf::Drawable</a>.
 * It is the base to others class for display selected scene of game.
 */
class View : public sf::Drawable
{
public:
    /*!
     * \brief Default constructor.
     */
    View();
    /*!
     * \brief Default virtual destructor.
     */
    virtual ~View();

    /*!
     * \brief updateView is the method for implementation in a target class.
     * You should use this method in order to update selected scene of game.
     */
    virtual void updateView()=0;

    /*!
     * \brief handleInputKeyboard is method for handling input witch keyboard.
     */
    virtual void handleInputKeyboard();

    /*!
     * \brief pressedKey is method check pres key of keyboard.
     * \param key is enum <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php">sf::Keyboard::Key</a>
     * \return return true if key is pres (change state with low to high), false otherwise
     */
    bool pressedKey(sf::Keyboard::Key key);

    /*!
     * \brief releasedKey is method check release key of keyboard.
     * \param key is enum <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Keyboard.php">sf::Keyboard::Key</a>
     * \return return true if key is release (change state with high to low), false otherwise
     */
    bool releasedKey(sf::Keyboard::Key key);

private:
    unsigned int m_selectMenuOptions {0};
};

#endif // VIEW_H
