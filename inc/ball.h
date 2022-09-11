#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <vector>

    /*!
     * \brief The Ball class inherit from <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php">sf::RectangleShape</a>.
     */
    class Ball : public sf::RectangleShape
    {
    public:
        /*!
         * \brief The Sensors enum
         */
        enum Sensors
        {
            X = 0,
            Y = 1
        };
        /*!
         * \brief Default constructor.
         */
        Ball();

        /*!
         * \brief setVelocity sets velocity of ball.
         * \param velocity is a value of velocity ball.
         */
        void setVelocity(sf::Vector2f velocity);

        /*!
         * \brief getVelocity gets velocity of ball.
         * \return return value of velocity.
         */
        sf::Vector2f getVelocity(void);

        /*!
         * \brief setPosition sets positions of ball.
         * \param x is position in x-axis.
         * \param y is position in y-axis.
         */
        void setPosition (float x, float y);

        /*!
         * \brief setPosition sets positions of ball.
         * \param position value of position.
         */
        void setPosition (const sf::Vector2f &position);

        /*!
         * \brief setSize sets size of ball.
         * \param size value of size.
         */
        void setSize (const sf::Vector2f &size);

        /*!
         * \brief velocityInvertX changes velocity sign for the x-axis.
         */
        void velocityInvertX();

        /*!
         * \brief velocityInvertY changes velocity sign for the y-axis.
         */
        void velocityInvertY();
        std::vector<sf::RectangleShape> & accesscollisionSensor();

    private:
        void draw (sf::RenderTarget &target, sf::RenderStates states) const;

        /*!
         * \brief setColisionSensorsPosition sets position of sensors on center ball.
         */
        void setColisionSensorsPosition();

        /*!
         * \brief setColisionSensorsSize sets the size of the sensors according to the speed of the ball and sets origin to the center of the sensor
         */
        void setColisionSensorsSize();



        sf::Vector2f m_velocity;                                    //! Velocity of the ball.
        std::vector<sf::RectangleShape> m_collisionSensor;          //! Vector collision sensors
    };


#endif // BALL_H
