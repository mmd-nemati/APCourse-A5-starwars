#include <iostream>
#include "src/rsdl.hpp"
#include "game/game.hpp"
int main(int argc, char *argv[])
{
    Game game(4);
    while(game.process_event())
    {
        game.render();
        
    }
    return 0;
}
