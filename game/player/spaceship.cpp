#include "../../src/rsdl.hpp"
#include "spaceship.hpp"


Spaceship::Spaceship()
  :  body(462, 668, 100, 100)
{
    location =  {462, 668};
    vx = INITIAL_VELOCITY;
    vy = INITIAL_VELOCITY;
    ax = SPACESHIP_ACCELERATION;
    ay = SPACESHIP_ACCELERATION;
    //body = Rectangle(location.x, location.y);
}

void Spaceship::move(int direction)
{
    if (direction == UP)
    {
        vy -= ay;
        location.y += vy;
        body = Rectangle(location.x, location.y, 100, 100);
    }
    else if (direction == DOWN)
    {
        vy += ay;
        location.y += vy;
        body = Rectangle(location.x, location.y, 100, 100);
    }
    if (direction == LEFT)
    {
        vx -= ax;
        location.x += vx;
        body = Rectangle(location.x, location.y, 100, 100);
    }
    else if (direction == RIGHT)
    {
        vx += ax;
        location.x += vx;
        body = Rectangle(location.x, location.y, 100, 100);
    }
}
///Spaceship::Spaceship()
  ///: body(100, 100, 100, 100)
///{
 ///   return;
///}