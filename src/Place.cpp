// Copyright © 2024 - Cleo Naughton

#include "Place.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Place::Place(string name)
{
  cout << "Place constructor called with " << name << endl;
  this->name = name;
}

string Place::getName()
{
  return this->name;
}

void Place::addExit(char direction, Place *destination)
{
  cout << "Adding exit from " << this->name << " " << direction << " to " << destination->name << endl;
  this->exits[direction] = destination;
}