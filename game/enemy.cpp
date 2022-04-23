#include "enemy.hpp"

Enemy::Enemy()
 :  body(0, 0, ENENMY_SCALE, ENENMY_SCALE)
{
    damage = ENEMY_DAMAGE;
}

Enemy::Enemy(Point _loc)
 : body(_loc.x, _loc.y, 56, 80)
{
    location = _loc;
    damage = ENEMY_DAMAGE;
}