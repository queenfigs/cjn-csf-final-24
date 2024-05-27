// Copyright © 2024 - Cleo Naughton

#ifndef PLACE_H
#define PLACE_H

#include <string>
#include <map>

using namespace std;

class Place
{
private:
  string name;
  string desc;
  // map from char (N, S, E, W) to Place
  map<char, Place *> exits;

public:
  Place(string name, string desc);
  string getName();
  string getDesc();
  void addExit(char direction, Place *destination);
  Place *getExit(char direction);
};

#endif // PLACE_H