#ifndef __MAP_H__
#define __MAP_H__
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
const std::string ROUNDS_MAP_DELIMITER = "#";
class Map
{
    public:
        Map(const std::string map_file_name);

        void read_map();
        
    private:
        std::ifstream map_file;
        std::vector<std::string> map_lines;
};
#endif