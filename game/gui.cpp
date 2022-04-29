#include "gui.hpp"
#include <string>
void GUI::draw_background(Window* win)
{
    win->draw_img("assets/photos/back.png");
}

void GUI::draw_spaceship(Window* win, Spaceship spaceship)
{
    win->draw_img("assets/photos/ship.png",spaceship.get_body());
}

void GUI::draw_enemies(Window* win, std::vector<Enemy*> enemies)
{
    for (int i = 0; i < enemies.size(); i++)
        if (enemies[i]->is_alive())
            win->draw_img("assets/photos/enemy-ship2.png", enemies[i]->get_body());
}

void GUI::draw_bullets(Window* win, std::vector<Bullet> bullets, int type)
{
    std::string photo_address;
    switch(type)
    {
        case SPACESHIP:
            photo_address = "assets/photos/ship-bullet.png";
            break;

        case ENEMY:
            photo_address = "assets/photos/enemy-bullet2.png";
            break;
    }

    for (int i = 0; i < bullets.size(); i++)
        win->draw_img(photo_address, 
        Rectangle(bullets[i].get_loc(), BULLET_SCALE, BULLET_SCALE));
}

void GUI::draw_hostages(Window* win, std::vector<Hostage*> hostages)
{
    for (int i = 0; i < hostages.size(); i++)
        win->draw_img("assets/photos/hostage.png", hostages[i]->get_body());
}

void GUI::show_lose(Window* win)
{
    win->show_text(LOSE_PROMPT_TEXT, Point(330, 330), RED, "assets/fonts/Meslo-Regular.ttf", 70);
}

void GUI::show_victory(Window* win)
{
    win->show_text(WIN_PROMPT_TEXT, Point(350, 330), GREEN, "assets/fonts/Meslo-Regular.ttf", 70);
}