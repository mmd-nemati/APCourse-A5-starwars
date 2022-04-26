#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "../src/rsdl.hpp"
#include "bullet.hpp"
#include "general.hpp"
#include <vector>

constexpr int ENEMY_INITIAL_HEALTH = 100;
constexpr int ENEMY_DAMAGE = 20;
constexpr int ENENMY_SCALE = 45;
class Enemy
{
    public:
        Enemy();
        Enemy(Point _loc);
        virtual void move();
        void shoot();
        void bullets_move();
        void hit_spaceship(Rectangle spaceship_body);
        void delete_bullet(int index);
        Rectangle get_body() { return body; }
        std::vector<Bullet> get_bullets() { return bullets; }
    protected:
        int health;
        Rectangle body;
        Point location;
        std::vector<Bullet> bullets;
        int damage;
};


#endif