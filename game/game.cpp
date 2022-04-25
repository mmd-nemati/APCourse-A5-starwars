#include "game.hpp"
#include <iostream>
#include <vector>
Game::Game(int r)
    : spaceship()
{
    counter = 0;
    rounds = r;
    win = new Window(1024, 768);
    game_status = GAME_RUNNING;
    flag = false;
    //dir = 0;
    //spaceship = Spaceship(win);
}

void Game::run()
{
    counter++;
    spaceship.move();
    spaceship.bullets_move();
    process_enemy_hit();
    move_enemies();
    if (this->can_enemies_shoot())
        enemies_shoot();
    enemies_bullets_move();
    enemies_bullets_hit();
    process_event();
    render();
    delay(30);
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
        win->draw_img("assets/photos/enemy-ship.png", enemies[i]->get_body());
        //win->draw_rect(enemies[i].get_body(), RED);
    
    for (int i = 0; i < enemies.size(); i++)
        for (int j = 0; j < enemies[i]->get_bullets().size(); j++)
            win->draw_img("assets/photos/enemy-bullet.png", enemies[i]->get_bullets()[j].get_body());;
            //win->draw_rect(enemies[i]->get_bullets()[j].get_body(), GREEN);

    win->update_screen();
    
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
    switch(new_event.get_type())
    {
        case Event::QUIT:
            game_status = GAME_STOPPED;

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
    Point p1(700, 50);
    Point p2(400, 50);
    Point p3(300, 100);
    Point p4(500, 200);
    Point p5(654, 100);
    Point p6(200, 250);
    Enemy* a = new Enemy(p1);
    Enemy* b = new Enemy(p2);
    Enemy* c = new Enemy(p3);
    Enemy* d = new Enemy(p4);
    enemies.push_back(a);
    enemies.push_back(b);
    enemies.push_back(c);
    enemies.push_back(d);
   // enemies.push_back(Enemy(p1));
    //enemies.push_back(Enemy(p2));
    //enemies.push_back(Enemy(p3));
    //enemies.push_back(Enemy(p4));
    //enemies.push_back(Enemy(p5));
    MovingEnemy* s = new  MovingEnemy(p6);
    enemies.push_back(s);
}

bool objects_conflict(Rectangle b1, Rectangle b2)
{   
    Rectangle hitbox(b2.x - b1.w, b2.y - b1.h, b2.w + b1.w, b2.h + b1.h);
    return ((hitbox.x <= b1.x && 
            b1.x <= hitbox.x + hitbox.w && 
            hitbox.y <= b1.y && 
            b1.y <= hitbox.y + hitbox.h));
    
}

void Game::process_enemy_hit()
{
    for (int i = 0; i < enemies.size(); i++)
        for (int j = 0; j < spaceship.get_bullets().size(); j++)
            if (objects_conflict(spaceship.get_bullets()[j].get_body(),
                enemies[i]->get_body()))
            { 
                spaceship.delete_bullet(j);
                delete_enemy(i);
                continue;           
            }
}

void Game::delete_enemy(int index)
{
    enemies.erase(enemies.begin() + index); 
}


void Game::move_enemies()
{
    for (int i = 0; i < enemies.size(); i++)
        enemies[i]->move();
}

bool Game::can_enemies_shoot()
{
    if (counter % 30 == 0 || counter % 30 == 4)
        return true;

    return false;
}

void Game::enemies_shoot()
{
    for (int i = 0; i < enemies.size(); i++)
        enemies[i]->shoot();
}
void Game::enemies_bullets_move()
{
    for (int i = 0; i < enemies.size(); i++)
        enemies[i]->bullets_move();
}

void Game::enemies_bullets_hit()
{
    for (int i = 0; i < enemies.size(); i++)
        for (int j = 0; j < enemies[i]->get_bullets().size(); j++)
            if (objects_conflict(spaceship.get_body(), enemies[i]->get_bullets()[j].get_body()))
            {    
                // implement lose function
                //std::cout << "LOSE" << std::endl;
                enemies[i]->delete_bullet(j);
                continue;
            }
}
/*bool is_out_of_map(Point _loc)
{
    return (_loc.x < 0 || _loc.x > 1024 || _loc.y < 0 || _loc.y > 768);
}*/

/*
void Game::bullets_move(std::vector<Bullet> bullets, int shooter)
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (is_out_of_map(bullets[i].get_loc()))
        {
            bullets.erase(bullets.begin() + i);
            continue;
        }
        switch(shooter)
        {
            case SPACESHIP_SHOOT:
                bullets[i].move(SPACESHIP_BULLET_SPEED);
                break;
            case ENEMY_SHOOT:
                bullets[i].move(ENEMY_BULLET_SPEED);
                break;
        }
    }
}
*/