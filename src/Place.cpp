// Copyright © 2024 - Cleo Naughton

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#include "Place.h"
#include "Thing.h"

Place::Place(string name, string desc)
{
  // cout << "Place constructor called with " << name << endl;
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
  this->exits[direction] = destination;
}

Place *Place::getExit(char direction)
{
  return this->exits[direction];
}

Thing *Place::getThings()
{
  return this->things;
}

void Place::addThing(Thing *thing)
{
  // special handling if the place has no things yet
  if (this->things == nullptr)
  {
    this->things = thing;
  }
  else
  {
    this->things->addThing(thing);
  }
}

void Place::removeThing(Thing *thing)
{
  if (this->things != nullptr)
  {
    // special handling if the thing to remove is the first thing in the list
    // because we need to update the head of the list.
    if (this->things == thing)
    {
      this->things = thing->getNextThing();
    }
    else
    {
      this->things->removeThing(thing);
    }
  }
}