#ifndef RECTANGLEOBJECT_H
#define RECTANGLEOBJECT_H

#include <SFML/Graphics.hpp>
#include <functional>


    /*!
     * \brief The RectangleObject class inherit from <a href="https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RectangleShape.php">sf::RectangleShape</a>.
     */
    class RectangleObject : public sf::RectangleShape
    {
    public:
        /*!
         * \brief The Sensors enum
         */
        enum Sensors
        {
            Top     = 0,
            Bottom  = 1,
            Left    = 2,
            Right   = 3
        };
        /*!
         * \brief Default constructor.
         */
        RectangleObject();

        /*!
         * \brief setVelocity sets velocity of object.
         * \param velocity is a value of velocity object.
         */
        void setVelocity(sf::Vector2f velocity);

        /*!
         * \brief setVelocity sets velocity of object.
         * \param x is a value of x-axis velocity.
         * \param y is a value of y-axis velocity.
         */
        void setVelocity(float x, float y);

        /*!
         * \brief getVelocity gets velocity of object.
         * \return return value of velocity.
         */
        sf::Vector2f getVelocity(void);

        /*!
         * \brief setPosition sets positions of object.
         * \param x is position in x-axis.
         * \param y is position in y-axis.
         */
        void setPosition (float x, float y);

        /*!
         * \brief setPosition sets positions of object.
         * \param position value of position.
         */
        void setPosition (const sf::Vector2f &position);

        /*!
         * \brief setSize sets size of object.
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

        /*!
         * \brief move changes position object on a window.
         * \param offsetX is value of shift object in x-axis on a window.
         * \param offsetY is value of shift object in y-axis on a window.
         */
        void move (float offsetX, float offsetY);

        /*!
         * \brief move changes position object on a window.
         * \param offset is value of shift object on a window.
         */
        void move (const sf::Vector2f &offset);

        /*!
         * \brief accesscollisionSensor gets access to collisionSensors.
         * \return reference to collisionSensors.
         */
        std::vector<sf::RectangleShape> & accesscollisionSensor();

        /*!
         * \brief checkMinDistCollisionX checks if forwarded object is the closet distance on x-axis of this object.
         * \param object to check distance.
         * \return returns true if forwarded object is the closet distance x-axis of this object. Else returns false.
         */
        bool checkMinDistCollisionX(const sf::Shape &object);

        /*!
         * \brief checkMinDistCollisionY checks if forwarded object is the closet distance on y-axis of this object.
         * \param object to check distance.
         * \return returns true if forwarded object is the closet distance y-axis of this object. Else returns false.
         */
        bool checkMinDistCollisionY(const sf::Shape &object);

        /*!
         * \brief resetMinDistCollision resets value of minimal distance to collision object.
         */
        void resetMinDistCollision();

        /*!
         * \brief functionCollisionX is a function or method for executed if is collision in x-axis.
         */
        std::function<void (void)>functionCollisionX;

        /*!
         * \brief functionCollisionY is a function or method for executed if is collision in y-axis.
         */
        std::function<void (void)>functionCollisionY;

    private:
//        void draw (sf::RenderTarget &target, sf::RenderStates states) const;

        /*!
         * \brief setColisionSensorsPosition sets position of sensors on center object.
         */
        void setColisionSensorsPosition();

        /*!
         * \brief setColisionSensorsSize sets the size of the sensors according to the speed of the object and sets origin to the center of the sensor
         */
        void setColisionSensorsSize();



        sf::Vector2f m_velocity;                                    //! Velocity of the object.
        std::vector<sf::RectangleShape> m_collisionSensor;          //! Vector collision sensors.
        sf::Clock m_clock;                                          //! Clock.
        sf::Time m_time;                                            //! Game deltaTime.
        sf::Vector2f m_minDistCollision;                            //! Value of minimal distance to collision object.
    };


#endif // RECTANGLEOBJECT_H
