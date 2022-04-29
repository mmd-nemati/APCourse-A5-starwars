#ifndef __GENERAL_H__
#define __GENERAL_H__
#include "../src/rsdl.hpp"
#include "constants.hpp"
//#include "game.hpp"
#include <string>
#include <vector>
namespace object
{
    enum GameBeings
    {
        ENEMY = 1,
        MOVING_ENEMY = 2,
        HOSTAGE = 3
    };
}

struct MapScale
{
    int column;
    int row;
};

bool objects_conflict(Rectangle b1, Rectangle b2);
std::vector<std::string> parse_line(std::string line);

/*void draw_background(Window* win);
void draw_spaceship(Window* win, Spaceship spaceship);
void draw_enemies(Window* win, std::vector<Enemy*> enemies);
void draw_bullets(Window* win, std::vector<Bullet> bullets);
void draw_hostages(Window* win, std::vector<Hostage*> hostages);
*/
#endif