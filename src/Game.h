// Copyright © 2024 - Cleo Naughton

#ifndef GAME_H
#define GAME_H

#include <string>

#include "Player.h"

class Game
{
private:
  // private for the player obv
  Player *player;

public:
  // constructor that passes game file
  Game(string filename);
  // starts game and reads input to print results, ie: N to direction to place
  void run();
};

#endif // GAME_H