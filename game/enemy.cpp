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

void Enemy::delete_bullet(int index)
{
    bullets.erase(bullets.begin() + index);
}
// stop bullet

void Enemy::move()
{
    //std::cout << "Moving" << std::endl;
    return;
}

void Enemy::hit_spaceship(Rectangle spaceship_body)
{
    for (int i = 0; i < bullets.size(); i++)
        if (objects_conflict(spaceship_body, bullets[i].get_body()))
        {   
             std::cout << "SHOT" << std::endl;
            this->delete_bullet(i);
        }

}