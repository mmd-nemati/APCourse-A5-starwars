#ifndef __BULLET_H__
#define __BULLET_H__
#include "../src/rsdl.hpp"

constexpr int BULLET_DAMAGE = 5;
constexpr int BULLET_SCALE = 5;
class Bullet
{
    public:
        Bullet();
    private:
        Point location;
        int damage;
        Rectangle body;

};
#endif