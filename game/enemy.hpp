#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "../src/rsdl.hpp"
#include "bullet.hpp"
//#include "spaceship.hpp"
#include "general.hpp"
#include <vector>

constexpr int ENEMY_INITIAL_HEALTH = 100;
constexpr int ENEMY_DAMAGE = 20;
constexpr int ENENMY_SCALE = 45;
constexpr int ALIVE = true;
constexpr bool DEAD = false;
class Enemy
{
    public:
        Enemy();
        Enemy(Point _loc);
        virtual void move();
        void shoot();
        void bullets_move();
        void die();
        bool is_alive();
        void delete_bullet(int index);
        void delete_all_bullets();
        Rectangle get_body() { return body; }
        std::vector<Bullet> get_bullets() { return bullets; }
    protected:
        bool status;
        Rectangle body;
        Point location;
        std::vector<Bullet> bullets;
};


#endif