#include "map.hpp"

Map::Map(const std::string map_file_name)
{
    //map_file.open(map_file_name.c_str());
    map_file.open(map_file_name);
}

void Map::read_map()
{
    std::string line;
    while (std::getline(map_file, line))
    {
        map_lines.push_back(line);
    }
}