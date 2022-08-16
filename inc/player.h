#ifndef PLAYER_H
#define PLAYER_H

#include "rectangleobject.h"

/*!
     * \brief The Player class inherit from RectangleObject.
     */
    class Player : public RectangleObject
    {
    public:
        /*!
         * \brief Player is a default constructor.
         */
        Player();

        /*!
         * \brief setPoints sets points of player.
         * \param points is a value of points.
         */
        void setPoints(int points);

        /*!
         * \brief getPoints gets value of points.
         * \return return value of points.
         */
        int getPoints(void);

        /*!
         * \brief addPoints adds points to player points
         * \param value of points to add.
         */
        void addPoints(int value);

    private:
        int m_points {0};           //! Value of points.
    };


#endif // PLAYER_H
