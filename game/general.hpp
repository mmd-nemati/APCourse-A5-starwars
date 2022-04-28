#ifndef __GENERAL_H__
#define __GENERAL_H__
#include "../src/rsdl.hpp"
#include <string>
#include <vector>
#include <ctime>
namespace objects
{
    enum GameObjects
    {
        ENEMY = 1,
        MOVING_ENEMY = 2,
        HOSTAGE = 3
    };
}

const std::string TOKENS_DELIMITER = "-";
bool objects_conflict(Rectangle b1, Rectangle b2);
std::vector<std::string> parse_line(std::string line);

struct MapScale
{
    int column;
    int row;
};
#endif