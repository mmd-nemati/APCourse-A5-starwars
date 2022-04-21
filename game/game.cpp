#include "game.hpp"
#include <iostream>
Game::Game(int r)
    : spaceship()
{
    rounds = r;
    win = new Window(1024, 768);
    game_status = GAME_STOPPED;
    //spaceship = Spaceship(win);
}

void Game:: render()
{
    win->clear();
    win->draw_img("assets/photos/back.png");
    win->draw_rect(spaceship.get_body(), RED);
    win->update_screen();
    delay(50);
}

bool Game:: process_event()
{
    Event new_event;
    if (this->win->has_pending_event())
    {
        new_event = this->win->poll_for_event();
        switch(new_event.get_type())
        {
            case Event::QUIT:
                return false;

        }
    }

    return true;
}