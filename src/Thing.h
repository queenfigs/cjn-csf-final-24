// Copyright © 2024 - Cleo Naughton

#ifndef THING_H
#define THING_H

#include <string>

using namespace std;

class Thing
{
private:
  string name;
  string desc;
  // here we are using a linked list to store the things
  // only because it is a requirement of the assignment
  // this also fulfills the requirement of using pointers
  Thing *nextThing;

public:
  // the thing constructor
  Thing(string name, string desc);

  // returns the name
  string getName();

  // returns the description
  string getDesc();

  // returns the next Thing in the linked list
  Thing *getNextThing();

  // sets next thing to null
  void nullNextThing();

  // Add a thing to the list of things.
  // Things are always added to the end of the list.
  Thing *addThing(Thing *thing);

  // Remove a thing from the list of things.
  Thing *removeThing(Thing *thing);
};

#endif // THING_H