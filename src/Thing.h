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
  Thing(string name, string desc);
  string getName();
  string getDesc();
  Thing *getNextThing();
  /**
   * Add a thing to the list of things.
   * Things are always added to the end of the list.
   *
   * @param thing the thing to add
   * @return the thing that was added
   */
  Thing *addThing(Thing *thing);
  /**
   * Remove a thing from the list of things.
   *
   * @param thing the thing to remove
   * @return the thing that was removed
   */
  Thing *removeThing(Thing *thing);
};

#endif // THING_H