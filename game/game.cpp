#include "game.hpp"
#include <iostream>
Game::Game(int r)
    : spaceship()
{
    rounds = r;
    win = new Window(1024, 768);
    game_status = GAME_STOPPED;
    flag = false;
    //dir = 0;
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

void Game::handle_key_press(int dir)
{
    /*if (event.get_pressed_key() == 'w')
        spaceship.move(UP);
    else if (event.get_pressed_key() == 's')
        spaceship.move(DOWN);
    else if (event.get_pressed_key() == 'a')
        spaceship.move(LEFT);
    else if (event.get_pressed_key() == 'd')
        spaceship.move(RIGHT);
    else    
        return;*/
    spaceship.move(dir);
}
int get_direction(Event &event)
{
    switch (event.get_pressed_key())
    {
        case 'w':
            return UP;
        case 's':
            return DOWN;
        case 'a':
            return LEFT;
        case 'd':
            return RIGHT;
    }

    return 0;
}
bool Game:: process_event()
{
    Event new_event;
    int dir = dir;
   // if (flag == true && new_event.get_type() != Event::KEY_RELEASE)
    //    handle_key_press(new_event);
    if (this->win->has_pending_event() || flag == true)
    {
        new_event = this->win->poll_for_event();
        //if (flag == true)
         //   handle_key_press(dir);
        switch(new_event.get_type())
        {
            case Event::QUIT:
                return false;
            
            case Event::KEY_PRESS:
                flag = true;
                dir = get_direction(new_event);
               // move_event = new_event;
                handle_key_press(dir);
            
            case Event::KEY_RELEASE:
                dir = 0;
                flag = false;

        }
    }


    return true;
}


