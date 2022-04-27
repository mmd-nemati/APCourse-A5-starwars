#include "general.hpp"

bool objects_conflict(Rectangle b1, Rectangle b2)
{   
    Rectangle hitbox(b2.x - b1.w, b2.y - b1.h, b2.w + b1.w, b2.h + b1.h);
    return ((hitbox.x <= b1.x && 
            b1.x <= hitbox.x + hitbox.w && 
            hitbox.y <= b1.y && 
            b1.y <= hitbox.y + hitbox.h));
    
}

void win_or_lose_check(int status)
{
    
}