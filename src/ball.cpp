#include "ball.h"
#include <math.h>
#include <iostream>

Ball::Ball()
{
    constexpr int quantitySensors = 2;              // Quantity menu options for display on this view.

    // Clear vector of the text, create new text and add this text into the vector.
    m_collisionSensor.clear();
    for(int i = 0; i < quantitySensors; i++)
    {
        sf::RectangleShape *tempBorder_ptr = new sf::RectangleShape;
        m_collisionSensor.push_back(*tempBorder_ptr);
//        delete tempText_ptr;      // I don't know why this doesn't work.
    }

}

void Ball::setVelocity(sf::Vector2f velocity)
{
     m_velocity = velocity;
}

sf::Vector2f Ball::getVelocity()
{
    return m_velocity;
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::Shape::draw(target, states);
//    for(const auto & sensor : m_collisionSensor)
//        target.draw(sensor);
}

void Ball::setColisionSensorsPosition()
{
//    std::cout << "Origin.x: " << getOrigin().x << " Origin.y: " << getOrigin().y <<std::endl;
    sf::Vector2f positionBall = getPosition();
    m_collisionSensor.at(Sensors::X).setPosition(positionBall);
    m_collisionSensor.at(Sensors::Y).setPosition(positionBall);


}

void Ball::setColisionSensorsSize()
{
    float size;
    static sf::Clock clock;

    sf::Vector2f sizeBall = getSize();

    // Sets size of a X sensor.
    size = std::abs(m_velocity.x) * clock.getElapsedTime().asSeconds()*2;
    m_collisionSensor.at(Sensors::X).setSize(sf::Vector2f(size+sizeBall.x,sizeBall.x/2));

    // Sets size of a Y sensor.
    size = std::abs(m_velocity.y) * clock.getElapsedTime().asSeconds()*2;
    m_collisionSensor.at(Sensors::Y).setSize(sf::Vector2f(sizeBall.y/2,size+sizeBall.y));

    // Sets origin for sensors.
    sf::FloatRect sensorRect;
    for(auto & sensor : m_collisionSensor)
    {
        sensorRect = sensor.getLocalBounds();
        sensor.setOrigin(sensorRect.width/2,sensorRect.height/2);
    }
    clock.restart();
}

void Ball::setPosition(float x, float y)
{
    sf::RectangleShape::setPosition(x, y);
    setColisionSensorsPosition();
}

void Ball::setPosition(const sf::Vector2f &position)
{
    sf::RectangleShape::setPosition(position);
    setColisionSensorsPosition();
}

void Ball::setSize(const sf::Vector2f &size)
{
    sf::RectangleShape::setSize(size);
    setColisionSensorsSize();
    setColisionSensorsPosition();
}

void Ball::velocityInvertX()
{
    m_velocity.x *= -1;
}

void Ball::velocityInvertY()
{
    m_velocity.y *= -1;
}

std::vector<sf::RectangleShape> &Ball::accesscollisionSensor()
{
    return m_collisionSensor;
}

