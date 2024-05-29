// Copyright © 2024 - Cleo Naughton

#include <string>
#include <iostream>

using namespace std;

#include "Thing.h"

Thing::Thing(string name, string desc)
{
  // cout << "Thing constructor called with " << name << endl;
  this->name = name;
  this->desc = desc;

  // initialize pointer from this thing to the next thing to null
  this->nextThing = nullptr;
}

string Thing::getName()
{
  return this->name;
}

string Thing::getDesc()
{
  return this->desc;
}

Thing *Thing::getNextThing()
{
  return this->nextThing;
}

void Thing::nullNextThing()
{
  // making this thing have no next thing
  this->nextThing = nullptr;
}

Thing *Thing::addThing(Thing *thing)
{
  // find the end of the list
  Thing *current = this;

  // while there is a next thing...
  while (current->nextThing != nullptr)
  {
    // move current thing to next thing
    current = current->nextThing;
  }
  // add our thing to the end of the list.
  current->nextThing = thing;
  // make sure our thing is the last thing in the list.
  thing->nextThing = nullptr;
  return thing;
}

Thing *Thing::removeThing(Thing *thing)
{
  // find thing in the list.
  Thing *current = this;

  // while the next thing is not the thing we passed in
  while (current->nextThing != thing)
  {
    // move current thing to next thing
    current = current->nextThing;
  }
  // remove thing from the list.
  // current next thing was pointing at thing, changed to point at thing's next thing was ;)
  current->nextThing = thing->nextThing;
  // make sure thing is no longer in the list.
  thing->nextThing = nullptr;
  return thing;
}