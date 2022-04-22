#include "../../src/rsdl.hpp"
#include "spaceship.hpp"


Spaceship::Spaceship()
  :  body(462, 668, 100, 100)
{
    location =  {462, 668};
    vx = INITIAL_VELOCITY;
    vy = INITIAL_VELOCITY;
    ax = MOVING_VELOCITY;
    ay = MOVING_VELOCITY;
    is_moving = false;
    //body = Rectangle(location.x, location.y);
}

void Spaceship::set_moving(int _dir)
{
    is_moving = true;
    dir = _dir;
}

void Spaceship::move()
{
    if (is_moving)
    {
        if (dir == UP)
        {
            vy = MOVING_VELOCITY;
            location.y -= vy;
            body = Rectangle(location.x, location.y, 100, 100);
        }
        else if (dir == DOWN)
        {
            vy = MOVING_VELOCITY;
            location.y += vy;
            body = Rectangle(location.x, location.y, 100, 100);
        }
        if (dir == LEFT)
        {
            vx = MOVING_VELOCITY;
            location.x -= vx;
            body = Rectangle(location.x, location.y, 100, 100);
        }
        else if (dir == RIGHT)
        {
            vx = MOVING_VELOCITY;
            location.x += vx;
            body = Rectangle(location.x, location.y, 100, 100);
        }
    }
}

void Spaceship::stop()
{
    vx = 0;
    vy = 0;
    is_moving = false;
}
///Spaceship::Spaceship()
  ///: body(100, 100, 100, 100)
///{
 ///   return;
///}