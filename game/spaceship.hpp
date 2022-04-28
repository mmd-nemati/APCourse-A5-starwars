#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__
#include "../src/rsdl.hpp"
#include "enemy.hpp"
#include "bullet.hpp"
#include "constants.hpp"
#include <vector>

class Spaceship 
{
    public:
        Spaceship();
        void put_on_map(Point _loc);
        void move();
        void stop();
        void shoot();
        void bullets_move();
        void delete_bullet(int index);
        void touch_enemy(Enemy *enemy);
        Rectangle get_body() { return body; };
        void win();
        void lose();
        void set_moving(int _dir);
        int get_dir() { return dir; }
        std::vector<Bullet> get_bullets() { return bullets; }
    private:
        Point location;
        double vx, vy;
        double ax, ay;
        Rectangle body;
        int dir;
        bool is_moving;
        std::vector<Bullet> bullets;
        int result;
};

#endif