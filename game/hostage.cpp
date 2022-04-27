#include "hostage.hpp"

Hostage::Hostage(Point _loc, double scale)
 : body(_loc.x, _loc.y, scale, scale)
{
    location = _loc;
}