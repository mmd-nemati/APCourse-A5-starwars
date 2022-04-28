#ifndef __BULLET_H__
#define __BULLET_H__
#include "../src/rsdl.hpp"
#include "constants.hpp"

class Bullet
{
    public:
        Bullet();
        Bullet(Point _loc);
        void move(double speed);
        bool is_out_of_map();
    
        void set_location(Point _loc);
        Point get_loc() { return location; }
        Rectangle get_body() { return body; }

    private:
        double vy;
        Point location;
        Rectangle body;
};
#endif