#ifndef __GAME_H__
#define __GAME_H__
#include "../src/rsdl.hpp"
#include "map.hpp"
#include "spaceship.hpp"
#include "enemy.hpp"
#include "movingenemy.hpp"
#include "hostage.hpp"
#include <vector>
constexpr int WINDOW_WIDTH = 1024;
constexpr int WINDOW_HEIGHT = 768;
constexpr bool GAME_RUNNING = true;
constexpr bool GAME_STOPPED = false;
constexpr int SPACESHIP_SHOOT = 1;
constexpr int ENEMY_SHOOT = 2;
constexpr int NO_RESULT = 0;
constexpr int WIN = 1;
constexpr int LOSE = 2;
class Game
{
    public: 
        Game(int r);
        void render();
        void run();
        void handle_key_press(int dir);
        bool process_event();
        void create_enemies();
        void spaceship_hit_enemy();
        void enemies_hit_spaceship();
        void spaceship_hit_hostage();
        void kill_enemy(int index);
        bool can_enemies_shoot();
        void enemies_shoot();
        void enemies_bullets_move();
        void spaceship_touch_others();
        void spaceship_touch_enemy();
        void spaceship_touch_hostage();
        void move_enemies();
        void player_lose();
        void player_win();
        void end();
        bool get_result() { return result; }       
    private:
        Window* win;
        int counter;
        int rounds;
        bool game_status;
        Spaceship spaceship;
        std::vector<Enemy*> enemies;
        std::vector<Hostage*> hostages;
        int result;
};
#endif