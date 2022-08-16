#include "Gui/gameview.h"
#include <iostream>

GameView::GameView(sf::RenderWindow & window) : View{window}
{
    setDisplayNextView(GameView::GraphicView::Player2);    // Sets default next view for display.
}

View::GraphicView GameView::updateView()
{
    setDisplayNextView(GraphicView::Player2);
    handleInputKeyboard();
    updateGame();
    accessWindow().draw(*this);
    return  getDisplayNextView();
}

void GameView::updateGame()
{
//    updateDletaTime();
    detectCollision();
    updateBounds();
    updateBall();
}

void GameView::updateDletaTime()
{
    m_deltaTime = m_clock.getElapsedTime();
    m_clock.restart();
}

void GameView::detectCollision()
{
        sf::Vector2f ballPosition;
        for(const auto & bound : m_boundsGame.accessBounds())
        {

            if(m_ball.accesscollisionSensor().at(Ball::Sensors::Y).getGlobalBounds().intersects(bound.getGlobalBounds()))
            {
                if(m_ball.getVelocity().y < 0)
                    m_ball.setPosition(m_ball.getPosition().x, bound.getPosition().y + bound.getLocalBounds().height + m_ball.getSize().y);
                else
                    m_ball.setPosition(m_ball.getPosition().x, bound.getPosition().y - bound.getLocalBounds().height - m_ball.getSize().y);
                m_ball.velocityInvertY();
            }
            if(m_ball.accesscollisionSensor().at(Ball::Sensors::X).getGlobalBounds().intersects(bound.getGlobalBounds()))
            {
                if(m_ball.getVelocity().x < 0)
                    m_ball.setPosition(bound.getPosition().x + bound.getLocalBounds().width + m_ball.getSize().x, m_ball.getPosition().y);
                else
                    m_ball.setPosition(bound.getPosition().x - bound.getLocalBounds().width - m_ball.getSize().x, m_ball.getPosition().y);
                m_ball.velocityInvertX();
            }
        }
}

void GameView::resetGame()
{
    sf::Vector2u windowSize = accessWindow().getSize();

    m_ball.setPosition(windowSize.x/2, windowSize.y/2);
    m_ball.setVelocity(sf::Vector2f(3000,5000));
}

void GameView::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    target.draw(m_ball);
    target.draw(m_boundsGame);
}

void GameView::handleInputKeyboard()
{
    if(!accessWindow().hasFocus())
        return;
    if(pressedKey(sf::Keyboard::Key::Escape))
    {
        setDisplayNextView(GraphicView::MENU);
    }
}

void GameView::updateBounds()
{
    m_boundsGame.setSize();
    m_boundsGame.setOrigin();
    m_boundsGame.setPosition();
}

void GameView::updateBall()
{
    sf::Vector2u windowSize = accessWindow().getSize();
    m_ball.setSize(sf::Vector2f(windowSize.y/60,windowSize.y/60));
    sf::FloatRect temp = m_ball.getLocalBounds();

    m_ball.setOrigin(temp.width/2, temp.height/2);

    sf::Vector2f velocityBall = m_ball.getVelocity();
    sf::Vector2f oldPosBall = m_ball.getPosition();
    sf::Vector2f newPosBall;

    newPosBall.x = oldPosBall.x + velocityBall.x * m_deltaTime.asSeconds();
    newPosBall.y = oldPosBall.y + velocityBall.y * m_deltaTime.asSeconds();
    m_ball.setPosition(newPosBall);
}
