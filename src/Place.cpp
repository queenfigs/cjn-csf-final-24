// Copyright © 2024 - Cleo Naughton

#include "Place.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Place::Place(string name, string desc)
{
  cout << "Place constructor called with " << name << endl;
  this->name = name;
  this->desc = desc;
}

string Place::getName()
{
  return this->name;
}

string Place::getDesc()
{
  return this->desc;
}

void Place::addExit(char direction, Place *destination)
{
  cout << "Adding exit from " << this->name << " " << direction << " to " << destination->name << endl;
  this->exits[direction] = destination;
}

Place *Place::getExit(char direction)
{
  return this->exits[direction];
}