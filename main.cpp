#include <iostream>
#include "src/rsdl.hpp"
#include "game/game.hpp"
int main(int argc, char *argv[])
{
    Game game(argv[1]);
    //game.translate_map(Map(argv[1]));
    //game.create_enemies();
    while(game.get_result() == NO_RESULT)
    {
        game.run();
    }
    game.end();
    return 0;
}
