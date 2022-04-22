#ifndef __BULLET_H__
#define __BULLET_H__
#include "../src/rsdl.hpp"

constexpr int BULLET_DAMAGE = 50;
constexpr int BULLET_SCALE = 10;
class Bullet
{
    public:
        Bullet(Point _loc);

        void set_location(Point _loc);
        Rectangle get_body() { return body; }
    private:
        Point location;
        int damage;
        Rectangle body;

};
#endif