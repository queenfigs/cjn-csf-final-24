// Copyright © 2024 - Cleo Naughton

#include "Place.h"
#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(Place *startingLocation)
{
  this->location = startingLocation;
  cout << "Player constructor called" << endl;
}

Place *Player::getLocation()
{
  return this->location;
}

void Player::move(char direction)
{
  Place *destination = this->location->getExit(direction);
  if (!destination)
  {
    cout << "No exit in direction " << direction << endl;
  }
  else
  {
    this->location = destination;
  }
}
