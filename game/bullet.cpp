#include "bullet.hpp"

Bullet::Bullet()
  :  body(0, 0, BULLET_SCALE, BULLET_SCALE)
{
    damage = BULLET_DAMAGE;
}