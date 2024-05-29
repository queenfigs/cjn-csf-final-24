// Copyright © 2024 - Cleo Naughton

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#include "Place.h"
#include "Thing.h"

// constructor for places, name and description
Place::Place(string name, string desc)
{
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

// adds exist to destination in direction
void Place::addExit(char direction, Place *destination)
{
  // exits is map from char to Place
  this->exits[direction] = destination;
}

// gets exit with direction
Place *Place::getExit(char direction)
{
  // returns exit from direction
  return this->exits[direction];
}

// gets header of list of things in place
Thing *Place::getThings()
{
  return this->things;
}

// adds things into thing list
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

// removes thing from list of things
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