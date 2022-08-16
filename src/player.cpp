#include "player.h"


Player::Player()
{

}

void Player::setPoints(int points)
{
    m_points = points;
}

int Player::getPoints()
{
    return m_points;
}

void Player::addPoints(int value)
{
    m_points += value;
}


