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

void Bullet::move(double speed)
{
    vy = speed;
    location.y += vy;
    body.x = location.x;
    body.y = location.y;
}

void Bullet::set_location(Point _loc)
{
    location = _loc;
}

bool Bullet::is_out_of_map()
{
      return (this->location.x < 0 || this->location.x > 1024 || this->location.y < 0 || this->location.y > 768);

}