#include "general.hpp"

bool objects_conflict(Rectangle b1, Rectangle b2)
{   
    Rectangle hitbox(b2.x - b1.w, b2.y - b1.h, b2.w + b1.w, b2.h + b1.h);
    return ((hitbox.x <= b1.x && 
            b1.x <= hitbox.x + hitbox.w && 
            hitbox.y <= b1.y && 
            b1.y <= hitbox.y + hitbox.h));
    
}

std::vector<std::string> parse_line(std::string line)
{
    std::vector<std::string> tokens;
    size_t pos = 0;

    while ((pos = line.find(TOKENS_DELIMITER)) != std::string::npos) 
    {
        tokens.push_back(line.substr(0, pos));
        line.erase(0, pos + TOKENS_DELIMITER.length());
    }   
    tokens.push_back(line.substr(0, pos));

    return tokens;
}