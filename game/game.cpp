#include "game.hpp"

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

Game::Game(int r)
{
    rounds = r;
    win = new Window();
    game_status = GAME_STOPPED;
    // spaceship = Spaceship();
}