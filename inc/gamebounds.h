#ifndef GAMEBOUNDS_H
#define GAMEBOUNDS_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "ball.h"

class GameBounds : public sf::Drawable
{
public:

    enum Bounds
    {
        Top = 0,
        Bottom,
        Left,
        Right
    };

    GameBounds();
    void setSize();
    void setOrigin();
    void setPosition();
    std::vector<sf::RectangleShape> & accessBounds();

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    std::vector<sf::RectangleShape> m_boundsGame;      //! Bounds of game.
};

#endif // GAMEBOUNDS_H
