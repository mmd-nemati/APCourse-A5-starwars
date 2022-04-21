#ifndef __SPACESHIP_H__
#define __SPACESHIP_H__
#include "../../src/rsdl.hpp"

constexpr double INITIAL_VELOCITY = 0;
constexpr double SPACESHIP_ACCELERATION = 0.1;
class Spaceship 
{
    public:
        Spaceship();
        //Spaceship(Window* win);
        Rectangle get_body() { return body; };
    private:
        Point location;
        double vx, vy;
        double ax, ay;
        Rectangle body;
};

#endif