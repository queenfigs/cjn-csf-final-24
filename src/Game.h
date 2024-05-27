// Copyright © 2024 - Cleo Naughton

#ifndef GAME_H
#define GAME_H

#include <string>

#include "Player.h"

class Game
{
private:
  Player *player;

public:
  Game(string filename);
  void run();
};

#endif // GAME_H