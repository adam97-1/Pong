#include "Gui/gameview.h"
#include <iostream>

GameView::GameView(sf::RenderWindow & window) : View{window}
{
    constexpr int quantityPlayers = 2;                              // Quantity menu options for display on this view.

    // Clear vector of the text, create new text and add this text into the vector.
    Player *tempPlayer_ptr = NULL;
    m_menuOptions.clear();
    for(int i = 0; i < quantityPlayers; i++)
    {
        tempPlayer_ptr = new Player;
        m_players.push_back(*tempPlayer_ptr);
        //        delete tempText_ptr;                              // I don't know why this doesn't work.
    }
    std::srand(std::time(NULL));                                    // Sets seed for rand.
    setDisplayNextView(GameView::GraphicView::Player2);             // Sets default next view for display.
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
    detectCollision();
    updateBall();
    updatePlayers();
}

void GameView::updateDletaTime()
{
    m_deltaTime = m_clock.restart();
}

void GameView::detectCollision()
{
    // Reset collision function.
    m_ball.resetMinDistCollision();
    m_ball.functionCollisionX = std::bind([]{});
    m_ball.functionCollisionY = std::bind([]{});

        // Collision witch game bounds
            // Collision ball
            if(m_ball.accesscollisionSensor().at(RectangleObject::Sensors::Top).getGlobalBounds().intersects(m_boundsGame.accessBounds().at(GameBounds::Bounds::Top).getGlobalBounds()))
            {
                if(m_ball.checkMinDistCollisionY(m_boundsGame.accessBounds().at(GameBounds::Bounds::Top)))
                    m_ball.functionCollisionY = [&] {
                      m_ball.setPosition(m_ball.getPosition().x, m_boundsGame.accessBounds().at(GameBounds::Bounds::Top).getPosition().y + m_boundsGame.accessBounds().at(GameBounds::Bounds::Top).getLocalBounds().height + m_ball.getSize().y/2);
                      m_ball.velocityInvertY();
                    };
            }
            if(m_ball.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(m_boundsGame.accessBounds().at(GameBounds::Bounds::Bottom).getGlobalBounds()))
            {
                m_ball.setPosition(m_ball.getPosition().x, m_boundsGame.accessBounds().at(GameBounds::Bounds::Bottom).getPosition().y - m_boundsGame.accessBounds().at(GameBounds::Bounds::Bottom).getLocalBounds().height - m_ball.getSize().y/2);
                if(m_ball.checkMinDistCollisionY(m_boundsGame.accessBounds().at(GameBounds::Bounds::Bottom)))
                    m_ball.functionCollisionY = [&] {
                        m_ball.setPosition(m_ball.getPosition().x, m_boundsGame.accessBounds().at(GameBounds::Bounds::Bottom).getPosition().y - m_boundsGame.accessBounds().at(GameBounds::Bounds::Bottom).getLocalBounds().height - m_ball.getSize().y/2);
                        m_ball.velocityInvertY();
                    };
            }
            if(m_ball.accesscollisionSensor().at(RectangleObject::Sensors::Right).getGlobalBounds().intersects(m_boundsGame.accessBounds().at(GameBounds::Bounds::Right).getGlobalBounds()))
            {
                if(m_ball.checkMinDistCollisionX(m_boundsGame.accessBounds().at(GameBounds::Bounds::Right)))
                    m_ball.functionCollisionX = [&]{
                        m_players.at(1).addPoints(1);
                        std::cout << "Player 1: " << std::to_string(m_players.at(1).getPoints()) << std::endl;
                        resetGame();
                    };
            }
            if(m_ball.accesscollisionSensor().at(RectangleObject::Sensors::Left).getGlobalBounds().intersects(m_boundsGame.accessBounds().at(GameBounds::Bounds::Left).getGlobalBounds()))
            {
                if(m_ball.checkMinDistCollisionX(m_boundsGame.accessBounds().at(GameBounds::Bounds::Left)))
                    m_ball.functionCollisionX = [&]{
                        m_players.at(0).addPoints(1);
                        std::cout << "Player 0: " << std::to_string(m_players.at(0).getPoints()) << std::endl;
                        resetGame();
                    };
            }

            // Collision players
            for(auto & player : m_players)
            {

                if(player.accesscollisionSensor().at(RectangleObject::Sensors::Top).getGlobalBounds().intersects(m_boundsGame.accessBounds().at(GameBounds::Bounds::Top).getGlobalBounds()))
                {
                    player.setPosition(player.getPosition().x, m_boundsGame.accessBounds().at(GameBounds::Bounds::Top).getPosition().y + m_boundsGame.accessBounds().at(GameBounds::Bounds::Top).getSize().y + player.getSize().y/2);
                    if(player.getVelocity().y < 0)
                        player.setVelocity(sf::Vector2f(0,0));
                }
                if(player.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(m_boundsGame.accessBounds().at(GameBounds::Bounds::Bottom).getGlobalBounds()))
                {
                    player.setPosition(player.getPosition().x, m_boundsGame.accessBounds().at(GameBounds::Bounds::Bottom).getPosition().y - m_boundsGame.accessBounds().at(GameBounds::Bounds::Bottom).getSize().y -  player.getSize().y/2);
                    if(player.getVelocity().y > 0)
                        player.setVelocity(sf::Vector2f(0,0));
                }
            }


        // Collision players witch ball
        for(auto & player : m_players)
        {
            if(m_ball.accesscollisionSensor().at(RectangleObject::Sensors::Right).getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                m_ball.setPosition(player.getPosition().x - player.getLocalBounds().width/2 - m_ball.getSize().x/2, m_ball.getPosition().y);
                if(m_ball.checkMinDistCollisionX(player))
                    m_ball.functionCollisionX = [&] {
                        m_ball.velocityInvertX();
                        sf::Vector2f ballVelosity = m_ball.getVelocity();
                        sf::Vector2u windowSize = accessWindow().getSize();
                        m_ball.setVelocity(sf::Vector2f(ballVelosity.x*1.1, (ballVelosity.y > 0) ? static_cast<int>(windowSize.y)/2+std::rand() % static_cast<int>(windowSize.y)/2 : -(static_cast<int>(windowSize.y)/2+std::rand() % static_cast<int>(windowSize.y)/2)));
                    };
            }
            if(m_ball.accesscollisionSensor().at(RectangleObject::Sensors::Left).getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                m_ball.setPosition(player.getPosition().x + player.getLocalBounds().width/2 + m_ball.getSize().x/2, m_ball.getPosition().y);
                if(m_ball.checkMinDistCollisionX(player))
                    m_ball.functionCollisionX = [&] {
                        m_ball.velocityInvertX();
                        sf::Vector2f ballVelosity = m_ball.getVelocity();
                        sf::Vector2u windowSize = accessWindow().getSize();
                        m_ball.setVelocity(sf::Vector2f(ballVelosity.x*1.1, (ballVelosity.y > 0) ? static_cast<int>(windowSize.y)/2+std::rand() % static_cast<int>(windowSize.y)/2 : -(static_cast<int>(windowSize.y)/2+std::rand() % static_cast<int>(windowSize.y)/2)));
                    };
            }
            if(m_ball.accesscollisionSensor().at(RectangleObject::Sensors::Bottom).getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                if(m_ball.checkMinDistCollisionY(player))
                    m_ball.functionCollisionY =  [&] {
                                m_ball.setPosition(m_ball.getPosition().x, player.getPosition().y - player.getLocalBounds().height/2 - m_ball.getSize().y/2);
                                m_ball.velocityInvertY();
                                player.setVelocity(0,0);
                    };
            }
            if(m_ball.accesscollisionSensor().at(RectangleObject::Sensors::Top).getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                if(m_ball.checkMinDistCollisionY(player))
                    m_ball.functionCollisionY = [&] {
                        m_ball.setPosition(m_ball.getPosition().x, player.getPosition().y + player.getLocalBounds().height/2 + m_ball.getSize().y/2);
                        m_ball.velocityInvertY();
                        player.setVelocity(0,0);
                      };
            }
        }

        // Execute collision function.
        m_ball.functionCollisionX();
        m_ball.functionCollisionY();
}

void GameView::resetGame()
{
    sf::Vector2u windowSize = accessWindow().getSize();

    sf::Vector2f startVelocity;
    startVelocity.x = (std::rand()%2) ? static_cast<int>(windowSize.y)/2+std::rand() % static_cast<int>(windowSize.y)/2 : -(static_cast<int>(windowSize.y)/2+std::rand() % static_cast<int>(windowSize.y)/2);
    startVelocity.y = (std::rand()%2) ? static_cast<int>(windowSize.y)/2+std::rand() % static_cast<int>(windowSize.y)/2 : -(static_cast<int>(windowSize.y)/2+std::rand() % static_cast<int>(windowSize.y)/2);

    m_ball.setPosition(windowSize.x/2, windowSize.y/2);
    m_ball.setVelocity(startVelocity);

    m_players.at(0).setPosition(windowSize.y/20, windowSize.y/2);
    m_players.at(1).setPosition(windowSize.x - windowSize.y/20, windowSize.y/2);
    m_players.at(0).setVelocity(sf::Vector2f(0,0));
    m_players.at(1).setVelocity(sf::Vector2f(0,0));
}

void GameView::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    target.draw(m_ball);
    target.draw(m_boundsGame);
    for(const auto & player : m_players)
        target.draw(player);
}

void GameView::handleInputKeyboard()
{
    float windowSizeY = static_cast<float>(accessWindow().getSize().y);
    if(!accessWindow().hasFocus())
        return;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        m_players.at(0).setVelocity(sf::Vector2f(0, -windowSizeY));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        m_players.at(0).setVelocity(sf::Vector2f(0, windowSizeY));
    }
    else
    {
        m_players.at(0).setVelocity(sf::Vector2f(0, 0));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        m_players.at(1).setVelocity(sf::Vector2f(0, -windowSizeY));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        m_players.at(1).setVelocity(sf::Vector2f(0, windowSizeY));
    }
    else
    {
        m_players.at(1).setVelocity(sf::Vector2f(0, 0));
    }
    if(pressedKey(sf::Keyboard::Key::Escape))
    {
        setDisplayNextView(GraphicView::MENU);
    }
}

void GameView::updateBall()
{
    sf::Vector2f velocityBall = m_ball.getVelocity();
    m_ball.move(velocityBall.x*m_deltaTime.asSeconds(), velocityBall.y*m_deltaTime.asSeconds());
}

void GameView::updatePlayers()
{
    for(auto & player : m_players)
    {
        sf::Vector2f velocityPlayer = player.getVelocity();
        player.move(velocityPlayer.x*m_deltaTime.asSeconds(), velocityPlayer.y*m_deltaTime.asSeconds());
    }
}

void GameView::onSettingsChangeResolution(sf::VideoMode videoMode)
{
    // Change size of ball
    m_ball.setSize(sf::Vector2f(videoMode.height/60,videoMode.height/60));
    sf::FloatRect temp = m_ball.getLocalBounds();
    m_ball.setOrigin(temp.width/2, temp.height/2);

    // Change size of players
    for(auto & player : m_players)
    {
        player.setSize(sf::Vector2f(videoMode.height/50, videoMode.height/8));
        sf::FloatRect temp = player.getLocalBounds();
        player.setOrigin(temp.width/2, temp.height/2);
    }

    // Change size of boundsGame
    m_boundsGame.setSize(videoMode);
    m_boundsGame.setOrigin();
    m_boundsGame.setPosition(videoMode);
}
