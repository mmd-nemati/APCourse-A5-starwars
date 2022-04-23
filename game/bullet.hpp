#ifndef __BULLET_H__
#define __BULLET_H__
#include "../src/rsdl.hpp"

constexpr int BULLET_DAMAGE = 50;
constexpr int BULLET_SCALE = 18;
constexpr double BULLET_SPEED = -20;
class Bullet
{
    public:
        Bullet();
        Bullet(Point _loc);
        void move();
    
        void set_location(Point _loc);
        Point get_loc() { return location; }
        Rectangle get_body() { return body; }

    private:
        double vy;
        Point location;
        int damage;
        Rectangle body;

};
#endif