#include "hostage.hpp"

Hostage::Hostage(Point _loc, double width, double height)
 : body(_loc.x, _loc.y, width, height)
{
    location = _loc;
}