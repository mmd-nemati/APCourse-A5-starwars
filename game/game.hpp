#ifndef __GAME_H__
#define __GAME_H__
#include "../src/rsdl.hpp"
#include "spaceship.hpp"
#include "enemy.hpp"
#include "movingenemy.hpp"
#include <vector>
constexpr int WINDOW_WIDTH = 1024;
constexpr int WINDOW_HEIGHT = 768;
constexpr bool GAME_RUNNING = true;
constexpr bool GAME_STOPPED = false;
constexpr int SPACESHIP_SHOOT = 1;
constexpr int ENEMY_SHOOT = 2;

class Game
{
    public: 
        Game(int r);
        void render();
        void run();
        void handle_key_press(int dir);
        bool process_event();
        void create_enemies();
        void process_enemy_hit();
        void delete_enemy(int index);
        bool can_enemies_shoot();
        void enemies_shoot();
        void enemies_bullets_move();
        void enemies_bullets_hit();
        void move_enemies();
        bool get_status() { return game_status; }       
    private:
        Window* win;
        int wc;
        int counter;
        int rounds;
        bool game_status;
        Spaceship spaceship;
        bool flag;
        std::vector<Enemy*> enemies;
       // int dir;
        //Event move_event;

};
#endif