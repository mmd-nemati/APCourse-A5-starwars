#ifndef __GAME_H__
#define __GAME_H__
#include "../src/rsdl.hpp"
#include "player/spaceship.hpp"

constexpr bool GAME_RUNNING = true;
constexpr bool GAME_STOPPED = false;

class Game
{
    public: 
        Game(int r);
        void run();

    private:
        Window* win;
        int rounds;
        bool game_status;
        Spaceship spaceship;
};
#endif