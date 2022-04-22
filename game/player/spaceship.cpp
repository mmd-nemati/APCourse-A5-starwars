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
    //body = Rectangle(location.x, location.y);
}

void Spaceship::move(int direction)
{
    if (direction == UP)
    {
        location.y -= MOVING_VELOCITY;
        body = Rectangle(location.x, location.y, 100, 100);
    }
    else if (direction == DOWN)
    {
        location.y += MOVING_VELOCITY;
        body = Rectangle(location.x, location.y, 100, 100);
    }
    if (direction == LEFT)
    {
        location.x -= MOVING_VELOCITY;
        body = Rectangle(location.x, location.y, 100, 100);
    }
    else if (direction == RIGHT)
    {
        location.x += MOVING_VELOCITY;
        body = Rectangle(location.x, location.y, 100, 100);
    }
}
///Spaceship::Spaceship()
  ///: body(100, 100, 100, 100)
///{
 ///   return;
///}