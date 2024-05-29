// Copyright © 2024 - Cleo Naughton

#include <iostream>

using namespace std;

#include "Place.h"
#include "Player.h"
#include "Thing.h"

// constructor for players starting location
Player::Player(Place *startingLocation)
{
  // points to location
  this->location = startingLocation;
}

Place *Player::getLocation()
{
  return this->location;
}

// pushes player from location to location
int Player::move(char direction)
{
  // checks to see if location has exit in input direction
  Place *destination = this->location->getExit(direction);
  if (!destination)
  {
    // return statement if input direction has no exit
    cout << "No exit in direction " << direction << endl;
    return 0;
  }
  else
  {
    // moves player
    this->location = destination;
    return 1;
  }
}

Thing *Player::getThings()
{
  // return header of linked list
  return this->things;
}

void Player::addThing(Thing *thing)
{
  // special handling if the player has no things yet
  if (this->things == nullptr)
  {
    // set header of list to thing that was just added
    this->things = thing;
  }
  else
  {
    // otherwise, call addThing on header of list
    this->things->addThing(thing);
  }
}

void Player::removeThing(Thing *thing)
{
  if (this->things != nullptr)
  {
    // special handling if the thing to remove is the first thing in the list
    // because we need to update the head of the list.
    if (this->things == thing)
    {
      // set header of list to thing were removing's next thing
      this->things = thing->getNextThing();
      // null the next thing
      thing->nullNextThing();
    }
    else
    {
      // remove thing from list
      this->things->removeThing(thing);
    }
  }
}

void Player::takeThing(Thing *thing)
{
  // remove thing from location
  this->location->removeThing(thing);
  // adds thing to players list of things
  this->addThing(thing);
}

void Player::dropThing(Thing *thing)
{
  // removes thing from players list of things
  this->removeThing(thing);
  // adds thing to location
  this->location->addThing(thing);
}