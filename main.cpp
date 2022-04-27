#include <iostream>
#include "src/rsdl.hpp"
#include "game/game.hpp"
int main(int argc, char *argv[])
{
    Game game(4);
    game.create_enemies();
    while(game.get_result() == NO_RESULT)
    {
        game.run();
    }
    game.end();
    return 0;
}
