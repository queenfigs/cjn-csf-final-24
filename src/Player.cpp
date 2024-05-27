// Copyright © 2024 - Cleo Naughton

#include <iostream>

using namespace std;

#include "Place.h"
#include "Player.h"
#include "Thing.h"

Player::Player(Place *startingLocation)
{
  this->location = startingLocation;
  // cout << "Player constructor called" << endl;
}

Place *Player::getLocation()
{
  return this->location;
}

int Player::move(char direction)
{
  Place *destination = this->location->getExit(direction);
  if (!destination)
  {
    cout << "No exit in direction " << direction << endl;
    return 0;
  }
  else
  {
    this->location = destination;
    return 1;
  }
}

Thing *Player::getThings()
{
  return this->things;
}

void Player::addThing(Thing *thing)
{
  // special handling if the player has no things yet
  if (this->things == nullptr)
  {
    this->things = thing;
  }
  else
  {
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
      this->things = thing->getNextThing();
    }
    else
    {
      this->things->removeThing(thing);
    }
  }
}

void Player::takeThing(Thing *thing)
{
  this->location->removeThing(thing);
  this->addThing(thing);
}

void Player::dropThing(Thing *thing)
{
  this->removeThing(thing);
  this->location->addThing(thing);
}