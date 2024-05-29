// Copyright © 2024 - Cleo Naughton

#ifndef PLACE_H
#define PLACE_H

// https://cplusplus.com/reference/map/map/
#include <map>
#include <string>

using namespace std;

#include "Thing.h"

class Place
{
private:
  string name;
  string desc;
  // map from char (n, s, e, w) to Place
  map<char, Place *> exits;
  // header of list of things in place
  Thing *things = nullptr;

public:
  // constructor for initializing place name and description
  Place(string name, string desc);
  // get name of place
  string getName();
  // gets description of place
  string getDesc();
  // collects header of list of things
  Thing *getThings();
  // declares that there is a place in direction of input
  void addExit(char direction, Place *destination);
  // gets exits if any, in the direction of input
  Place *getExit(char direction);
  // adds thing to list of things in place
  void addThing(Thing *thing);
  // removes things from list of things in place
  void removeThing(Thing *thing);
};

#endif // PLACE_H