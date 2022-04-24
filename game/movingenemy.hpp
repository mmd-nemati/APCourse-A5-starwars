#ifndef __MOVING_ENEMY_H__
#define __MOVING_ENEMY_H__
#include "enemy.hpp"
#include "../src/rsdl.hpp"
constexpr double INITIAL_MOVING_ENEMY_X_SPEED = 20;
class MovingEnemy : public Enemy
{
    public:
        MovingEnemy(Point _loc);
        virtual void move();
        bool goes_out();
    protected:
        int vx;
};


#endif