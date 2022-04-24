#ifndef __BULLET_H__
#define __BULLET_H__
#include "../src/rsdl.hpp"

constexpr int BULLET_SCALE = 18;
constexpr double SPACESHIP_BULLET_SPEED = -20;
constexpr double ENEMY_BULLET_SPEED = 20;
class Bullet
{
    public:
        Bullet();
        Bullet(Point _loc);
        void move(double speed);
        bool is_out_of_map();
    
        void set_location(Point _loc);
        Point get_loc() { return location; }
        Rectangle get_body() { return body; }

    private:
        double vy;
        Point location;
        Rectangle body;
};
#endif