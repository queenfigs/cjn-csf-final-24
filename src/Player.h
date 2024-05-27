// Copyright © 2024 - Cleo Naughton

#ifndef PLAYER_H
#define PLAYER_H

#include "Place.h"
#include "Thing.h"

class Player
{
private:
  Place *location;
  Thing *things = nullptr;

public:
  Player(Place *startingLocation);
  Place *getLocation();
  int move(char direction);
  Thing *getThings();
  void addThing(Thing *thing);
  void removeThing(Thing *thing);
  void takeThing(Thing *thing);
  void dropThing(Thing *thing);
};

#endif // PLAYER_H