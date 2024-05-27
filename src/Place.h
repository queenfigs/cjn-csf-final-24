// Copyright © 2024 - Cleo Naughton

#ifndef PLACE_h
#define PLACE_h

#include <string>
#include <map>

using namespace std;

class Place
{
private:
  string name;
  // map from char (N, S, E, W) to Place
  map<char, Place *> exits;

public:
  Place(string name);
  string getName();
  void addExit(char direction, Place *destination);
};

#endif // PLACE_h