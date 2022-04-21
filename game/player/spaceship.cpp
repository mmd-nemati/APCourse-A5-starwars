#include "../../src/rsdl.hpp"
#include "spaceship.hpp"


Spaceship::Spaceship()
  :  body(462, 668, 100, 100)
{
    // location =  random?;
    vx = INITIAL_VELOCITY;
    vy = INITIAL_VELOCITY;
    ax = SPACESHIP_ACCELERATION;
    ay = SPACESHIP_ACCELERATION;
}

///Spaceship::Spaceship()
  ///: body(100, 100, 100, 100)
///{
 ///   return;
///}