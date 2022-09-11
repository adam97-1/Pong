//#include "racket.hpp"

//Pong::Racket::Racket(sf::Vector2f position)
//{
//    if(position.x > -1) this->position.x = -1;
//    else if(position.x < -WINDOW_WIGHT + RACKET_WIGHT) this->position.x = -WINDOW_WIGHT + RACKET_WIGHT;
//    else this->position.x = position.x;
//    if(position.y > -1) this->position.y = -1;
//    else if(position.y < -WINDOW_HEIGHT + RACKET_HEIGHT) this->position.y = -WINDOW_HEIGHT + RACKET_HEIGHT;
//    else this->position.y = position.y;

//    m_racket_hitbox.setOrigin(position);
//    m_racket_hitbox.setFillColor(sf::Color::White);
//    m_racket_hitbox.setSize(size);
//}

//Pong::Racket::~Racket()
//{

//}

//void Pong::Racket::setPosition(sf::Vector2f position)
//{

//    if(position.x > -1) this->position.x = -1;
//    else if(position.x < -WINDOW_WIGHT + RACKET_WIGHT) this->position.x = -WINDOW_WIGHT + RACKET_WIGHT;
//    else this->position.x = position.x;
//    if(position.y > -1) this->position.y = -1;
//    else if(position.y < -WINDOW_HEIGHT + RACKET_HEIGHT) this->position.y = -WINDOW_HEIGHT + RACKET_HEIGHT;
//    else this->position.y = position.y;
//    m_racket_hitbox.setOrigin(this->position);
//}

//sf::Vector2f Pong::Racket::getPosition()
//{
//    return position;
//}

//void Pong::Racket::changePosition(int value)
//{
//    position.y += value;
//    if(position.x > -1) position.x = -1;
//    if(position.x < -WINDOW_WIGHT + RACKET_WIGHT) position.x = -WINDOW_WIGHT + RACKET_WIGHT;
//    if(position.y > -1) position.y = -1;
//    if(position.y < -WINDOW_HEIGHT + RACKET_HEIGHT) position.y = -WINDOW_HEIGHT + RACKET_HEIGHT;
//    m_racket_hitbox.setOrigin(this->position);
//}

//void Pong::Racket::setSize(sf::Vector2f size)
//{
//    if(size.x < 1) this->size.x = 1;
//    else this->size.x = size.x;
//    if(size.y < 1) this->size.y = 1;
//    else this->size.y = size.y;
//    m_racket_hitbox.setSize(this->size);


//}

//void Pong::Racket::setVelocity(float velocity)
//{
//    m_velocity = velocity;
//}

//float Pong::Racket::getVelocity()
//{
//    return m_velocity;
//}

//sf::Vector2f Pong::Racket::getSize()
//{
//    return size;
//}

//sf::RectangleShape& Pong::Racket::accessRacketHitbox()
//{
//    return m_racket_hitbox;
//}

//void Pong::Racket::draw(sf::RenderTarget &target, sf::RenderStates states) const
//{
//    target.draw(m_racket_hitbox, states);
//}




