// Copyright © 2024 - Cleo Naughton

#ifndef PLACE_H
#define PLACE_H

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
  Thing *things = nullptr;

public:
  Place(string name, string desc);
  string getName();
  string getDesc();
  Thing *getThings();
  void addExit(char direction, Place *destination);
  Place *getExit(char direction);
  void addThing(Thing *thing);
  void removeThing(Thing *thing);
};

#endif // PLACE_H