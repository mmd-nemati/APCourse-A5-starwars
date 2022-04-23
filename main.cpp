#include <iostream>
#include "src/rsdl.hpp"
#include "game/game.hpp"
int main(int argc, char *argv[])
{
    Game game(4);
    bool game_running = true;
    game.create_enemies();
    while(game_running)
    {
        game_running = game.process_event();
        game.render();
    }
    return 0;
}
