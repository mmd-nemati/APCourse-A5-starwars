#ifndef __GAME_H__
#define __GAME_H__
#include "../src/rsdl.hpp"
#include "player/spaceship.hpp"

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
    private:
        Window* win;
        int rounds;
        bool game_status;
        Spaceship spaceship;
        bool flag;
       // int dir;
        //Event move_event;

};
#endif