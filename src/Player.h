// Copyright © 2024 - Cleo Naughton

#ifndef PLAYER_H
#define PLAYER_H

#include "Place.h"
#include "Thing.h"

class Player
{
private:
  // where player is
  Place *location;

  // what things player has
  Thing *things = nullptr;

public:
  // constructor for player setting start location
  Player(Place *startingLocation);
  // gets player location
  Place *getLocation();
  // moves player in direction, returning 1 if the player moves, and 0 if the player couldnt
  int move(char direction);
  // gets you the pointer to players first thing, or null if the player has no things
  Thing *getThings();
  // adds thing to your list of things
  void addThing(Thing *thing);
  // remove thing from your list of things
  void removeThing(Thing *thing);
  // takes thing from location to put into your list of things
  void takeThing(Thing *thing);
  // removes thing from list of things back into the location you are in
  void dropThing(Thing *thing);
};

#endif // PLAYER_H