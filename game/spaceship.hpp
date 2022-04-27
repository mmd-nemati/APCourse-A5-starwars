#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__
#include "../src/rsdl.hpp"
#include "enemy.hpp"
#include "bullet.hpp"
#include <vector>
constexpr int SPACESHIP_HEIGHT = 125;
constexpr int SPACESHIP_WIDTH = 69;
constexpr double INITIAL_VELOCITY = 0;
constexpr double MOVING_VELOCITY = 20;
constexpr int UP = 1;
constexpr int DOWN = 2;
constexpr int LEFT = 3;
constexpr int RIGHT = 4;
constexpr int NO_RESULT = 0;
constexpr int WIN = 1;
constexpr int LOSE = 2;
class Spaceship 
{
    public:
        Spaceship();
        //Spaceship(Window* win);
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