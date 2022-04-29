#ifndef __MOVING_ENEMY_H__
#define __MOVING_ENEMY_H__
#include "enemy.hpp"
#include "../src/rsdl.hpp"
#include "constants.hpp"

class MovingEnemy : public Enemy
{
    public:
        MovingEnemy(Point _loc);

        bool goes_out();
        virtual void move();
    protected:
        int vx;
};
#endif