#include "bullet.hpp"


Bullet::Bullet()
 : body(0, 0, BULLET_SCALE, BULLET_SCALE)
{
    location = {0, 0};
}
Bullet::Bullet(Point _loc)
  : body(_loc.x, _loc.y, BULLET_SCALE, BULLET_SCALE)
{
    location = {_loc.x, _loc.y};
}

void Bullet::move()
{
    vy = BULLET_SPEED;
    location.y += vy;
    body.x = location.x;
    body.y = location.y;
}

void Bullet::set_location(Point _loc)
{
    location = _loc;
}
