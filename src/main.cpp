// Copyright © 2024 - Cleo Naughton

#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
  cout << "Cleo Naughton's Final CSF Spring 2024 Project" << endl;

  auto adv = new Game("../src/game.txt");

  adv->run();
}