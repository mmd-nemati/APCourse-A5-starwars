#ifndef __GAME_H__
#define __GAME_H__
#include "../src/rsdl.hpp"
#include "general.hpp"
#include "map.hpp"
#include "gui.hpp"
#include "spaceship.hpp"
#include "enemy.hpp"
#include "movingenemy.hpp"
#include "hostage.hpp"
#include "constants.hpp"
#include <vector>
#include <string>
#include <ctime>
class Game
{
    public: 
        Game(const std::string map_file_name);

        void translate_map(Map &map, int offset);
        void init_round(int round);
        void receive_initial_data(std::vector<std::string> map_lines);
        void create_object(int type, MapScale scale);
        void render();
        void run(int cur_round);
        bool process_event();
        void spaceship_shoot_enemy();
        void enemies_shoot_spaceship();
        void spaceship_shoot_hostage();
        bool can_enemies_shoot();
        void enemies_shoot();
        void enemies_bullets_move();
        void bullets_move();
        void spaceship_shoot_others();
        void spaceship_touch_others();
        void spaceship_touch_enemy();
        void spaceship_touch_hostage();
        void move_enemies();
        void player_lose();
        void player_win();
        void win_check(int cur_round);
        void end();
        int get_rounds() { return rounds_num; }
    private:
        Map map;
        Window* win;
        GUI gui;
        int columns;
        int rows;
        int counter;
        int rounds_num;
        int objects_number;
        Spaceship spaceship;
        std::vector<Enemy*> enemies;
        std::vector<Hostage*> hostages;
        int result;
};
#endif