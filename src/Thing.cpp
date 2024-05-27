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

Thing *Thing::addThing(Thing *thing)
{
  // find the end of the list
  auto current = this;
  while (current->nextThing != nullptr)
  {
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
  auto current = this;
  while (current->nextThing != thing)
  {
    current = current->nextThing;
  }
  // remove thing from the list.
  current->nextThing = thing->nextThing;
  // make sure thing is no longer in the list.
  thing->nextThing = nullptr;
  return thing;
}