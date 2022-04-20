#include "game.hpp"

Game::Game(int r)
{
    rounds = r;
    win = new Window();
    game_status = GAME_STOPPED;
    // spaceship = Spaceship();
}

void Game:: render()
{
    win->clear();
    win->draw_img("assets/photos/back.png");
    win->update_screen();
}