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
};

#endif // VIEW_H
