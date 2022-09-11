#ifndef GAMEBOUNDS_H
#define GAMEBOUNDS_H

#include <SFML/Graphics.hpp>
#include <vector>

/*!
 * \brief The GameBounds class is a bounds of game. It inherits from <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php">sf::RectangleShape</a>.
 * It is create from four <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php"sf::RectangleShape</a>.
 */
class GameBounds : public sf::Drawable
{
public:

    /*!
     * \brief The Bounds enum of bounds of game.
     */
    enum Bounds
    {
        Top = 0,
        Bottom,
        Left,
        Right
    };

    /*!
     * \brief GameBounds is a default constructor.
     */
    GameBounds();

    /*!
     * \brief setSize sets size of bounds.
     * \param windowSize is a size of window.
     */
    void setSize(sf::VideoMode windowSize);

    /*!
     * \brief setOrigin sets origin of bounds.
     */
    void setOrigin();

    /*!
     * \brief setPosition sets position of bounds.
     * \param windowSize is a size of window.
     */
    void setPosition(sf::VideoMode windowSize);

    /*!
     * \brief accessBounds gets access for elements of bounds
     * \return return reference of sf::RectangleShape.
     */
    std::vector<sf::RectangleShape> & accessBounds();

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<sf::RectangleShape> m_boundsGame;      //! Bounds of game.
};

#endif // GAMEBOUNDS_H

