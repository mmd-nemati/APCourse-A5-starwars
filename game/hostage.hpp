#ifndef __HOSTAGE_H__
#define __HOSTAGE_H__
#include "../src/rsdl.hpp"
#include "constants.hpp"

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