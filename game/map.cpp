#include "map.hpp"

Map::Map(const std::string map_file_name)
{
    map_file.open(map_file_name);
    parse_map();
}

void Map::parse_map()
{
    std::string line;
    while (std::getline(map_file, line))
    {
        lines.push_back(line);
    }
}