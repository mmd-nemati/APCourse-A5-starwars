
#include "src/rsdl.hpp"
#include "game/game.hpp"
int main(int argc, char *argv[])
{
        Game game(4);
    while(true)
    {
        game.render();
        delay(100);
    }
    return 0;
}
