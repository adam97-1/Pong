#include "rectangleobject.h"
#include <math.h>
#include <iostream>

RectangleObject::RectangleObject()
{
    constexpr int quantitySensors = 4;              // Quantity menu options for display on this view.

    // Clear vector of the text, create new text and add this text into the vector.
    m_collisionSensor.clear();
    for(int i = 0; i < quantitySensors; i++)
    {
        sf::RectangleShape *tempBorder_ptr = new sf::RectangleShape;
        m_collisionSensor.push_back(*tempBorder_ptr);
//        delete tempText_ptr;      // I don't know why this doesn't work.
    }
    // Sets red color for sensors (use only of debug)
    for(auto & sensor : m_collisionSensor)
    {
        sensor.setFillColor(sf::Color::Red);
    }
    resetMinDistCollision();

}

void RectangleObject::setVelocity(sf::Vector2f velocity)
{
     m_velocity = velocity;

     // Execute setColisionSensorsSize because sensor size is directly proportional of velocity.
     setColisionSensorsSize();
}

void RectangleObject::setVelocity(float x, float y)
{
    m_velocity.x = x;
    m_velocity.y = y;

    // Execute setColisionSensorsSize because sensor size is directly proportional of velocity.
    setColisionSensorsSize();
}

sf::Vector2f RectangleObject::getVelocity()
{
    return m_velocity;
}

// Only for debug

//void RectangleObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
//{
//    sf::Shape::draw(target, states);
//    for(const auto & sensor : m_collisionSensor)
//        target.draw(sensor);
//}

void RectangleObject::setColisionSensorsPosition()
{
    sf::Vector2f rectangePos = getPosition();
    sf::Vector2f rectangleSize = getSize();
    m_collisionSensor.at(Sensors::Top).setPosition(rectangePos.x, rectangePos.y - rectangleSize.y/2);
    m_collisionSensor.at(Sensors::Bottom).setPosition(rectangePos.x, rectangePos.y + rectangleSize.y/2);
    m_collisionSensor.at(Sensors::Left).setPosition(rectangePos.x - rectangleSize.x/2, rectangePos.y);
    m_collisionSensor.at(Sensors::Right).setPosition(rectangePos.x + rectangleSize.x/2, rectangePos.y);


}

void RectangleObject::setColisionSensorsSize()
{
    m_time = m_clock.restart();
    float size;
    sf::Vector2f rectangleSize = getSize();

    // Sets size of a X sensor.
    size = getVelocity().x*m_time.asSeconds()*1.1+2; // Size of senor is directly proportional of velocity. Minimal size is 2.
    // if object hes positive velocity sets Left sensor to minimal size.
    m_collisionSensor.at(Sensors::Left).setSize(sf::Vector2f((size < 0) ? -size : 2, rectangleSize.y));
    // if object hes negative velocity sets Right sensor to minimal size.
    m_collisionSensor.at(Sensors::Right).setSize(sf::Vector2f((size >= 0) ? size : 2, rectangleSize.y));

    // Sets size of a Y sensor.
    size = getVelocity().y*m_time.asSeconds()*1.1+2; // Size of senor is directly proportional of velocity. Minimal size is 2.
    // if object hes positive velocity sets Top sensor to minimal size.
    m_collisionSensor.at(Sensors::Top).setSize(sf::Vector2f(rectangleSize.x, (size < 0) ? -size : 2));
    // if object hes negative velocity sets Bottom sensor to minimal size.
    m_collisionSensor.at(Sensors::Bottom).setSize(sf::Vector2f(rectangleSize.x, (size >= 0) ? size : 2));

    // Sets origin for sensors.
    sf::FloatRect sensorRect;

    sensorRect = m_collisionSensor.at(Sensors::Left).getLocalBounds();
    m_collisionSensor.at(Sensors::Left).setOrigin(sensorRect.width,sensorRect.height/2);
    sensorRect = m_collisionSensor.at(Sensors::Right).getLocalBounds();
    m_collisionSensor.at(Sensors::Right).setOrigin(sensorRect.left,sensorRect.height/2);
    sensorRect = m_collisionSensor.at(Sensors::Top).getLocalBounds();
    m_collisionSensor.at(Sensors::Top).setOrigin(sensorRect.width/2,sensorRect.height);
    sensorRect = m_collisionSensor.at(Sensors::Bottom).getLocalBounds();
    m_collisionSensor.at(Sensors::Bottom).setOrigin(sensorRect.width/2,sensorRect.top);

}

void RectangleObject::setPosition(float x, float y)
{
    sf::RectangleShape::setPosition(x, y);
    setColisionSensorsPosition();
}

void RectangleObject::setPosition(const sf::Vector2f &position)
{
    sf::RectangleShape::setPosition(position);
    setColisionSensorsPosition();
}

void RectangleObject::setSize(const sf::Vector2f &size)
{
    sf::RectangleShape::setSize(size);
    setColisionSensorsSize();
    setColisionSensorsPosition();
}

void RectangleObject::velocityInvertX()
{
    m_velocity.x *= -1;
}

void RectangleObject::velocityInvertY()
{
    m_velocity.y *= -1;
}

void RectangleObject::move(float offsetX, float offsetY)
{
    setColisionSensorsSize();
    sf::RectangleShape::move(offsetX,offsetY);
    for(auto & sensor : m_collisionSensor)
        sensor.move(offsetX,offsetY);
}

void RectangleObject::move(const sf::Vector2f &offset)
{
    setColisionSensorsSize();
    sf::RectangleShape::move(offset);
    for(auto & sensor : m_collisionSensor)
        sensor.move(offset);
}

std::vector<sf::RectangleShape> &RectangleObject::accesscollisionSensor()
{
    return m_collisionSensor;
}

bool RectangleObject::checkMinDistCollisionY(const Shape &object)
{
    sf::Vector2f position1 = object.getPosition();
    sf::Vector2f position2 = getPosition();
    if(std::abs(position1.y-position2.y) < m_minDistCollision.y)
    {
        m_minDistCollision.y =  std::abs(position1.y-position2.y);
        return true;
    }
    return false;
}

bool RectangleObject::checkMinDistCollisionX(const sf::Shape &object)
{
    sf::Vector2f position1 = object.getPosition();
    sf::Vector2f position2 = getPosition();
    if(std::abs(position1.x-position2.x) < m_minDistCollision.x)
    {
        m_minDistCollision.x =  std::abs(position1.x-position2.x);
        return true;
    }
    return false;
}

void RectangleObject::resetMinDistCollision()
{
    m_minDistCollision.x = 100000;
    m_minDistCollision.y = 100000;
}


