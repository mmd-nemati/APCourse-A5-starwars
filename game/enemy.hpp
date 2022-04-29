#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "../src/rsdl.hpp"
#include "bullet.hpp"
#include "general.hpp"
#include "constants.hpp"
#include <vector>

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