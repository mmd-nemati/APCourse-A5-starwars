#include <iostream>
#include "src/rsdl.hpp"
#include "game/game.hpp"
int main(int argc, char *argv[])
{
    Game game(argv[1]);
    for (int i = 1; i <= game.get_rounds(); i++)
       // while(game.get_result() == NO_RESULT)
            game.run(i);
        
    game.end();
    return 0;
}