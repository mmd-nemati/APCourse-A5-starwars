#ifndef __GAME_H__
#define __GAME_H__
#include "../src/rsdl.hpp"
#include "spaceship.hpp"
#include "enemy.hpp"
#include <vector>
constexpr int WINDOW_WIDTH = 1024;
constexpr int WINDOW_HEIGHT = 768;
constexpr bool GAME_RUNNING = true;
constexpr bool GAME_STOPPED = false;

class Game
{
    public: 
        Game(int r);
        void render();
        void run();
        void handle_key_press(int dir);
        bool process_event();
        void create_enemies();
        bool objects_conflict(Rectangle b1, Rectangle b2);
        void check_enemy_hit();
    private:
        Window* win;
        int rounds;
        bool game_status;
        Spaceship spaceship;
        bool flag;
        std::vector<Enemy> enemies;
       // int dir;
        //Event move_event;

};
#endif