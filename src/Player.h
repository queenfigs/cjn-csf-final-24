// Copyright © 2024 - Cleo Naughton

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>
#include "Place.h"

using namespace std;

class Player
{
private:
  Place *location;

public:
  Player(Place *startingLocation);
  Place *getLocation();
  void move(char direction);
};

#endif // PLAYER_H