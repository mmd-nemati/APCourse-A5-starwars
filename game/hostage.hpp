#ifndef __HOSTAGE_H__
#define __HOSTAGE_H__
#include "../src/rsdl.hpp"

constexpr double HOSTAGE_SCALE = 30;
class Hostage
{
    public:
        Hostage(Point _loc, double scale = HOSTAGE_SCALE);
        
        Rectangle get_body() { return body; }
    private:
        Rectangle body;
        Point location;

};
#endif