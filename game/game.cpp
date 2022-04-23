#include "game.hpp"
#include <iostream>
#include <vector>
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
    win->draw_img("assets/photos/ship.png",spaceship.get_body());
    //win->draw_rect(spaceship.get_body());
    for (int i = 0; i < spaceship.get_bullets().size(); i++)
        win->draw_img("assets/photos/ship-bullet.png", 
        Rectangle(spaceship.get_bullets()[i].get_loc(), BULLET_SCALE, BULLET_SCALE));
        //win->draw_rect(spaceship.get_bullets()[i].get_body(), WHITE);
        //win->draw_img("assets/photos/ship-bullet.png", spaceship.get_bullets()[i].get_body());

    for (int i = 0; i < enemies.size(); i++)
        win->draw_img("assets/photos/enemy-ship.png", enemies[i].get_body());
        //win->draw_rect(enemies[i].get_body(), RED);

    win->update_screen();
    delay(30);
}

void Game::handle_key_press(int dir)
{
    spaceship.move();
}

int get_move_direction(Event &event)
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
    int d;
    new_event = this->win->poll_for_event();
    spaceship.move();
    spaceship.bullets_move();
    switch(new_event.get_type())
    {
        case Event::QUIT:
            return false;

        case Event::KEY_PRESS:
        {
            char pressed_key = new_event.get_pressed_key();
            if (pressed_key == 'w')
                spaceship.set_moving(UP);
            if (pressed_key == 's')
                spaceship.set_moving(DOWN);
            if (pressed_key == 'a')
                spaceship.set_moving(LEFT);
            if (pressed_key == 'd')
                spaceship.set_moving(RIGHT);
            if (pressed_key == ' ')
                spaceship.shoot();
                //std::cout << "yes" << std::endl;
            //d = get_move_direction(new_event);
            break;
        }
        
        case Event::KEY_RELEASE:
            if (spaceship.get_dir() == get_move_direction(new_event))
                spaceship.stop();
            break;        
        
        default:;
        
    }
    return true;
}

void Game::create_enemies()
{
    // this is a temp implementaion
    Point p1 = {200, 50};
    Point p2 = {400, 50};
    Point p3 = {300, 100};
    enemies.push_back(Enemy(p1));
    enemies.push_back(Enemy(p2));
    enemies.push_back(Enemy(p3));
}