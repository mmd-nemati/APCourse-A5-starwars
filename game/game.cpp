#include "game.hpp"
#include <iostream>
#include <vector>

Game::Game(const std::string map_file_name)
    : gui(), map(map_file_name), spaceship() 
{
    srand(time(0));
    receive_initial_data(map.get_lines());
    counter = 0;
    objects_number = 0;
    win = new Window(WINDOW_WIDTH, WINDOW_HEIGHT);
    result = NO_RESULT;
}

void Game::receive_initial_data(std::vector<std::string> map_lines)
{
    std::vector<std::string> tokens;
    tokens = parse_line(map_lines[0]);
    columns = stoi(tokens[0]);
    rows = stoi(tokens[1]);
    
    tokens = parse_line(map_lines[1]);
    rounds_num = stoi(tokens[0]);
}

void Game::translate_map(Map &map, int round)
{
    std::vector<std::string> map_lines = map.get_lines();
    std::vector<std::string> tokens;
    for (int i = (2 + round + objects_number); i < map_lines.size(); ++i)
    {
        tokens = parse_line(map_lines[i]);
        if (tokens[0] == ROUNDS_MAP_DELIMITER)
            break;

        MapScale section = {stoi(tokens[1]), stoi(tokens[2])};
        if (tokens[0] == ENEMY_MAP)
            create_object(object::ENEMY, section);
        
        if (tokens[0] == MOVING_ENEMY_MAP)
            create_object(object::MOVING_ENEMY, section);
        
        if (tokens[0] == HOSTAGE_MAP)
            create_object(object::HOSTAGE, section);
    }
}

void Game::create_object(int type, MapScale section)
{
    double width_offset = (WINDOW_WIDTH / columns) * (section.column - 1);
    double height_offset = (WINDOW_HEIGHT / rows) * (section.row - 1);
    Point _loc = Point(width_offset, height_offset);
    switch (type)
    {
        case object::ENEMY:
        {
            Enemy* new_enemy = new Enemy(_loc);
            enemies.push_back(new_enemy);
            break;
        }
        case object::MOVING_ENEMY:
        {
            MovingEnemy* new_m_enemy = new MovingEnemy(_loc);
            enemies.push_back(new_m_enemy);
            break;
        }
        case object::HOSTAGE:
        {
            Hostage* new_hostage = new Hostage(_loc);
            hostages.push_back(new_hostage);
            break;
        }
        default:
            return;
    }

    objects_number++;
}

void Game::init_round(int round)
{
    counter = -50;
    for (int i = 0; i < enemies.size(); i++)
        enemies[i]->delete_all_bullets();
    enemies.clear();
    hostages.clear();

    int rand_loc = rand();
    Point _loc = {rand_loc % WINDOW_WIDTH, WINDOW_HEIGHT-SPACESHIP_HEIGHT};
    spaceship.put_on_map(_loc);

    translate_map(map, round);
}

void Game::run(int cur_round)
{
    init_round(cur_round);
    while (result == NO_RESULT)
    {
        render();
        process_event();

        counter++;
        spaceship.move();
        bullets_move();
        spaceship_shoot_others();
        spaceship_touch_others();
        move_enemies();
        enemies_shoot();

        win_check(cur_round);
        delay(30);
    }
    if (cur_round != rounds_num && result == WIN)
          result = NO_RESULT;
}

void Game::render()
{
    win->clear();

    gui.draw_background(win);
    gui.draw_spaceship(win, spaceship);
    gui.draw_enemies(win, enemies);
    gui.draw_hostages(win, hostages);
    gui.draw_bullets(win, spaceship.get_bullets(), SPACESHIP);
    for (int i = 0; i < enemies.size(); i++)
        gui.draw_bullets(win, enemies[i]->get_bullets(), ENEMY);
    
    win->update_screen();
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

void Game::spaceship_shoot_enemy()
{
    for (int i = 0; i < enemies.size(); i++)
        for (int j = 0; j < spaceship.get_bullets().size(); j++)
            if (objects_conflict(spaceship.get_bullets()[j].get_body(),
                enemies[i]->get_body()) && enemies[i]->is_alive())
            { 
                spaceship.delete_bullet(j);
                enemies[i]->die();
                continue;           
            }
}

void Game::enemies_shoot_spaceship()
{
    for (int i = 0; i < enemies.size(); i++)
        for (int j = 0; j < enemies[i]->get_bullets().size(); j++)
            if (objects_conflict(spaceship.get_body(),
                enemies[i]->get_bullets()[j].get_body()))
            {   
                enemies[i]->delete_bullet(j);
                result = LOSE;
                continue;
            }
}

void Game::spaceship_shoot_hostage()
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
        if (objects_conflict(spaceship.get_body(), 
            enemies[i]->get_body()) && enemies[i]->is_alive())
                player_lose();
}

void Game::spaceship_touch_hostage()
{
    for (int i = 0; i < hostages.size(); i++)
        if (objects_conflict(spaceship.get_body(), 
            hostages[i]->get_body()))
                player_lose();
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
    if (!can_enemies_shoot())
        return;
    for (int i = 0; i < enemies.size(); i++)
        if (enemies[i]->is_alive())
            enemies[i]->shoot();
}

void Game::enemies_bullets_move()
{
    for (int i = 0; i < enemies.size(); i++)
        enemies[i]->bullets_move();
}

void Game::bullets_move()
{
    spaceship.bullets_move();
    enemies_bullets_move();
}

void Game::spaceship_shoot_others()
{
    spaceship_shoot_enemy();
    spaceship_shoot_hostage();
}

void Game::spaceship_touch_others()
{
    this->enemies_shoot_spaceship();
    this->spaceship_touch_enemy();
    this->spaceship_touch_hostage();
}

void Game::win_check(int cur_round)
{
    for (int i = 0; i < enemies.size(); i++)
        if (enemies[i]->is_alive())
            return;
    
    player_win();
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
        gui.draw_background(win);
        
        switch(result)
        {   
            case LOSE:   
                gui.show_lose(win);
                break;
            
            case WIN:
                gui.show_victory(win);
                break;
        }     

        win->update_screen();
        process_event();
        delay(50);
    }
}