#ifndef __MAP_H__
#define __MAP_H__
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
const std::string ROUNDS_MAP_DELIMITER = "#";
const std::string ENEMY_MAP = "E";
const std::string MOVING_ENEMY_MAP = "M";
const std::string HOSTAGE_MAP = "H";
class Map
{
    public:
        Map(const std::string map_file_name);

        void parse_map();
        std::vector<std::string> get_lines() { return lines; }
    private:
        std::vector<std::string> lines;
        std::ifstream map_file;
};
#endif