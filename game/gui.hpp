#ifndef __GUI_H__
#define __GUI_H__
#include "../src/rsdl.hpp"
#include "spaceship.hpp"
#include "enemy.hpp"
#include "hostage.hpp"
#include <vector>

class GUI
{
    public:
        GUI() { return; }
        
        void draw_background(Window* win);
        void draw_spaceship(Window* win, Spaceship spaceship);
        void draw_enemies(Window* win, std::vector<Enemy*> enemies);
        void draw_bullets(Window* win, std::vector<Bullet> bullets, int type);
        void draw_hostages(Window* win, std::vector<Hostage*> hostages);
        void show_lose(Window* win);
        void show_victory(Window* win);
};

#endif