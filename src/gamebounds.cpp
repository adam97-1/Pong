#include "gamebounds.h"

GameBounds::GameBounds()
{
    constexpr int quantityBoundsGame = 4;              // Quantity menu options for display on this view.

    // Clear vector of the text, create new boundsGame and add this boundsGame into the vector.
    m_boundsGame.clear();
    for(int i = 0; i < quantityBoundsGame; i++)
    {
        sf::RectangleShape *tempBoundsGame_ptr = new sf::RectangleShape;
        m_boundsGame.push_back(*tempBoundsGame_ptr);
//        delete tempText_ptr;      // I don't know why this doesn't work.
    }
}


std::vector<sf::RectangleShape> &GameBounds::accessBounds()
{
    return m_boundsGame;
}

void GameBounds::setOrigin()
{
    // Sets origin of bounds.
    sf::FloatRect tempBounds = m_boundsGame.at(Bounds::Bottom).getLocalBounds();
    m_boundsGame.at(Bounds::Bottom).setOrigin(tempBounds.left, tempBounds.height);

    tempBounds = m_boundsGame.at(Bounds::Top).getLocalBounds();
    m_boundsGame.at(Bounds::Top).setOrigin(tempBounds.left, tempBounds.top);

    tempBounds = m_boundsGame.at(Bounds::Right).getLocalBounds();
    m_boundsGame.at(Bounds::Right).setOrigin(tempBounds.width, tempBounds.top);

    tempBounds = m_boundsGame.at(Bounds::Left).getLocalBounds();
    m_boundsGame.at(Bounds::Left).setOrigin(tempBounds.left, tempBounds.top);
}

void GameBounds::setPosition(sf::VideoMode windowSize)
{

    // Sets positions of bounds.
    m_boundsGame.at(Bounds::Bottom).setPosition(0,windowSize.height);
    m_boundsGame.at(Bounds::Top).setPosition(0, 0);
    m_boundsGame.at(Bounds::Right).setPosition(windowSize.width, 0);
    m_boundsGame.at(Bounds::Left).setPosition(0, 0);
}

void GameBounds::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    for(const auto & bound : m_boundsGame)
        target.draw(bound);
}

void GameBounds::setSize(sf::VideoMode windowSize)
{
    // Sets size of bounds.
    m_boundsGame.at(Bounds::Bottom).setSize(sf::Vector2f(windowSize.width, windowSize.height/50));
    m_boundsGame.at(Bounds::Top).setSize(sf::Vector2f(windowSize.width, windowSize.height/50));
    m_boundsGame.at(Bounds::Right).setSize(sf::Vector2f(windowSize.height/50, windowSize.height));
    m_boundsGame.at(Bounds::Left).setSize(sf::Vector2f(windowSize.height/50, windowSize.height));
}