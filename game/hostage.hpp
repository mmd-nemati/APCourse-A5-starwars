#ifndef __HOSTAGE_H__
#define __HOSTAGE_H__
#include "../src/rsdl.hpp"

constexpr double HOSTAGE_SCALE = 30;
constexpr double HOSTAGE_WIDTH = 50;
constexpr double HOSTAGE_HEIGHT = 31;
class Hostage
{
    public:
        Hostage(Point _loc, double width = HOSTAGE_WIDTH, double height = HOSTAGE_HEIGHT);
        
        Rectangle get_body() { return body; }
    private:
        Rectangle body;
        Point location;

};
#endif