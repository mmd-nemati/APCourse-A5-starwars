#include "enemy.hpp"

Enemy::Enemy()
 :  body(0, 0, ENENMY_SCALE, ENENMY_SCALE)
{
    health = ENEMY_INITIAL_HEALTH;
    damage = ENEMY_DAMAGE;
}