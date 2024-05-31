// Copyright © 2024 - Cleo Naughton

#include <iostream>

using namespace std;

#include "Game.h"

int main()
{
  cout << "Cleo Naughton's Final CSF Spring 2024 Project" << endl;

  Game *game = new Game("../src/game.txt");

  game->run();
}