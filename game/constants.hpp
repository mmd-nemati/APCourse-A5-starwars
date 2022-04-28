#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

#include <string>

constexpr int WINDOW_WIDTH = 1024;
constexpr int WINDOW_HEIGHT = 768;
constexpr bool GAME_RUNNING = true;
constexpr bool GAME_STOPPED = false;
constexpr int SPACESHIP_SHOOT = 1;
constexpr int ENEMY_SHOOT = 2;
constexpr int NO_RESULT = 0;
constexpr int WIN = 1;
constexpr int LOSE = 2;
constexpr double HOSTAGE_SCALE = 30;
constexpr double HOSTAGE_WIDTH = 50;
constexpr double HOSTAGE_HEIGHT = 31;
constexpr int BULLET_SCALE = 18;
constexpr double SPACESHIP_BULLET_SPEED = -20;
constexpr double ENEMY_BULLET_SPEED = 10;
constexpr int SPACESHIP_HEIGHT = 90;
constexpr int SPACESHIP_WIDTH = 50;
constexpr double INITIAL_VELOCITY = 0;
constexpr double MOVING_VELOCITY = 20;
constexpr int UP = 1;
constexpr int DOWN = 2;
constexpr int LEFT = 3;
constexpr int RIGHT = 4;
constexpr int ENEMY_INITIAL_HEALTH = 100;
constexpr int ENEMY_DAMAGE = 20;
constexpr int ENENMY_SCALE = 45;
constexpr int ALIVE = true;
constexpr bool DEAD = false;
const std::string WIN_PROMPT_TEXT = "VICTORY!";
const std::string LOSE_PROMPT_TEXT = "YOU DIED!";
const std::string ROUNDS_MAP_DELIMITER = "#";
const std::string ENEMY_MAP = "E";
const std::string MOVING_ENEMY_MAP = "M";
const std::string HOSTAGE_MAP = "H";
constexpr double INITIAL_MOVING_ENEMY_X_SPEED = 20;

#endif