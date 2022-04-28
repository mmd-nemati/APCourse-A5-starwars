#include "game.hpp"
#include "general.hpp"
#include <iostream>
#include <vector>
Game::Game(const std::string map_file_name)
    : map(map_file_name), spaceship()
{
    translate_map(map);
    counter = 0;
    objects_number = 0;
    win = new Window(1024, 768);
    result = NO_RESULT;
}

void Game::receive_initial_data(std::vector<std::string> map_lines)
{
    std::vector<std::string> tokens;
    tokens = parse_line(map_lines[0]);
    columns = stoi(tokens[0]);
    rows = stoi(tokens[1]);
    
    tokens = parse_line(map_lines[1]);
    rounds = stoi(tokens[0]);
}

void Game::translate_map(Map &map)
{
    std::vector<std::string> map_lines = map.get_lines();
    std::vector<std::string> tokens;
    receive_initial_data(map_lines);
    for (int i = 3; i < map_lines.size(); ++i)
    {
        tokens = parse_line(map_lines[i]);
        if (tokens[0] == ROUNDS_MAP_DELIMITER)
            break;

        MapScale section = {stoi(tokens[1]), stoi(tokens[2])};
        if (tokens[0] == ENEMY_MAP)
            create_object(objects::ENEMY, section);
        
        if (tokens[0] == MOVING_ENEMY_MAP)
            create_object(objects::MOVING_ENEMY, section);
        
        if (tokens[0] == HOSTAGE_MAP)
            create_object(objects::HOSTAGE, section);
    }
}

void Game::create_object(int type, MapScale section)
{
    objects_number++;
    double width_offset = (1024 / columns) * (section.column - 1);
    double height_offset = (768 / rows) * (section.row - 1);
    Point _loc = Point(width_offset, height_offset);
    switch (type)
    {
        case objects::ENEMY:
        {
            Enemy* new_enemy = new Enemy(_loc);
            enemies.push_back(new_enemy);
            break;
        }

        case objects::MOVING_ENEMY:
        {
            MovingEnemy* new_m_enemy = new MovingEnemy(_loc);
            enemies.push_back(new_m_enemy);
            break;
        }
        case objects::HOSTAGE:
        {
            Hostage* new_hostage = new Hostage(_loc);
            hostages.push_back(new_hostage);
            break;
        }
    }
}

void Game::run()
{
    render();
    counter++;
    spaceship.move();
    spaceship.bullets_move();
    spaceship_hit_enemy();
    spaceship_hit_hostage();
    move_enemies();
    if (this->can_enemies_shoot())
        enemies_shoot();
    enemies_bullets_move();
    //enemies_hit_spaceship();
    spaceship_touch_others();
    process_event();
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
        if (enemies[i]->is_alive())
            win->draw_img("assets/photos/enemy-ship2.png", enemies[i]->get_body());
        //win->draw_rect(enemies[i].get_body(), RED);
    
    for (int i = 0; i < enemies.size(); i++)
        for (int j = 0; j < enemies[i]->get_bullets().size(); j++)
            win->draw_img("assets/photos/enemy-bullet2.png", enemies[i]->get_bullets()[j].get_body());;
            //win->draw_rect(enemies[i]->get_bullets()[j].get_body(), GREEN);

    for (int i = 0; i < hostages.size(); i++)
        win->draw_img("assets/photos/hostage.png", hostages[i]->get_body());
        //win->draw_rect(hostages[i]->get_body());

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
            exit(0);

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

void Game::spaceship_hit_enemy()
{
    for (int i = 0; i < enemies.size(); i++)
        for (int j = 0; j < spaceship.get_bullets().size(); j++)
            if (objects_conflict(spaceship.get_bullets()[j].get_body(),
                enemies[i]->get_body()) && enemies[i]->is_alive())
            { 
                spaceship.delete_bullet(j);
                kill_enemy(i);
                continue;           
            }
}

void Game::enemies_hit_spaceship()
{
    for (int i = 0; i < enemies.size(); i++)
        for (int j = 0; j < enemies[i]->get_bullets().size(); j++)
            if (objects_conflict(spaceship.get_body(),
                enemies[i]->get_bullets()[j].get_body()))
            {   
                enemies[i]->delete_bullet(j);
                player_lose();
                continue;
            }
}

void Game::spaceship_hit_hostage()
{
    for (int i = 0; i < hostages.size(); i++)
        for (int j = 0; j < spaceship.get_bullets().size(); j++)
            if (objects_conflict(spaceship.get_bullets()[j].get_body(), 
                hostages[i]->get_body()))
                    player_lose();
}

void Game::spaceship_touch_enemy()
{
    for (int i = 0; i < enemies.size(); i++)
        if (objects_conflict(spaceship.get_body(), enemies[i]->get_body()) && enemies[i]->is_alive())
            player_lose();
}

void Game::spaceship_touch_hostage()
{
    for (int i = 0; i < hostages.size(); i++)
        if (objects_conflict(spaceship.get_body(), hostages[i]->get_body()))
            player_lose();
}

void Game::kill_enemy(int index)
{
    enemies[index]->die();
}

void Game::move_enemies()
{
    for (int i = 0; i < enemies.size(); i++)
        if (enemies[i]->is_alive())
            enemies[i]->move();
}

bool Game::can_enemies_shoot()
{
    if (counter % 50 == 1 || counter % 50 == 5)
        return true;

    return false;
}

void Game::enemies_shoot()
{
    for (int i = 0; i < enemies.size(); i++)
        if (enemies[i]->is_alive())
            enemies[i]->shoot();
}

void Game::enemies_bullets_move()
{
    for (int i = 0; i < enemies.size(); i++)
        enemies[i]->bullets_move();
}


void Game::spaceship_touch_others()
{
    // hit hostages
    this->enemies_hit_spaceship();
    this->spaceship_touch_enemy();
    this->spaceship_touch_hostage();
}

void Game::player_lose()
{
    result = LOSE;
}

void Game::player_win()
{
    result = WIN;
}

void Game::end()
{
    while(true)
    {
        switch(result)
        {   
            case LOSE:   
                win->draw_img("assets/photos/back.png");
                win->show_text("game over you stupid fucking donkey!", Point(150, 300), WHITE, "assets/fonts/FreeSans.ttf", 45);
                break;
            
            case WIN:
                win->draw_img("assets/photos/back.png");
                win->show_text("The stupid wins!", Point(150, 300), WHITE, "assets/fonts/FreeSans.ttf", 45);
                break;
        }     

        win->update_screen();
        process_event();
        delay(50);
    }
}