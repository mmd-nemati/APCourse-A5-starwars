#include "enemy.hpp"

Enemy::Enemy()
    :  body(0, 0, ENENMY_WIDTH, ENEMY_HEIGHT)
{
    status = ALIVE;
}

Enemy::Enemy(Point _loc)
    : body(_loc.x, _loc.y, ENENMY_WIDTH, ENEMY_HEIGHT)
{
    location = _loc;
    status = ALIVE;
}

void Enemy::shoot()
{
    Point weapon_location = {location.x + body.w/2, location.y + body.h};
    Bullet new_bullet(weapon_location);
    new_bullet.set_location(weapon_location);
    bullets.push_back(new_bullet);
}

void Enemy::bullets_move()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (bullets[i].is_out_of_map())
        {
            bullets.erase(bullets.begin() + i);
            continue;
        }
        bullets[i].move(ENEMY_BULLET_SPEED);
    }
}

void Enemy::move()
{
    return;
}

void Enemy::delete_bullet(int index)
{
    bullets.erase(bullets.begin() + index);
}

void Enemy::delete_all_bullets()
{
    for (int i = 0; i < bullets.size(); i++)
        delete_bullet(i);
}

void Enemy::die()
{
    status = DEAD;
}

bool Enemy::is_alive()
{
    return (status == ALIVE);
}