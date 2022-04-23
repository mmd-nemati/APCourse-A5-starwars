#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "../src/rsdl.hpp"
#include "bullet.hpp"
#include <vector>

constexpr int ENEMY_INITIAL_HEALTH = 100;
constexpr int ENEMY_DAMAGE = 20;
constexpr int ENENMY_SCALE = 45;
class Enemy
{
    public:
        Enemy();
        Enemy(Point _loc);
    
        Rectangle get_body() { return body; }
    private:
        int health;
        Rectangle body;
        Point location;
        std::vector<Bullet> bullets;
        int damage;
};


#endif