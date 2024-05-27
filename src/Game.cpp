// Copyright © 2024 - Cleo Naughton

#include <string>
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

#include "Game.h"
#include "Place.h"
#include "Player.h"
#include "to_lower.h"

Game::Game(string filename)
{
  // cout << "Game constructor called with " << filename << endl;

  // here we are using file i/o to load the game from a file.
  ifstream sourceFile(filename);
  // check to see if it the file was opened.
  if (sourceFile.is_open())
  {
    // cout << "Loading game from " << filename << "..." << endl;
  }
  else
  {
    // print file not found message and exit.
    cout << "File named " << filename << " does not exist." << endl;
    exit(1);
  }

  // the first place we find will be the starting place.
  Place *startPlace = nullptr;
  // store map from place names to places.
  map<string, Place *> places;
  // store map from thing names to things.
  map<string, Thing *> things;

  // read each line of input file into line
  string line;
  // tracking which line number we are on.
  int lineNumber = 0;
  while (getline(sourceFile, line))
  {
    lineNumber++;
    if (line.length() == 0)
    {
      // skip empty lines
      continue;
    }
    // the first character of each line is the instruction.
    char instruction = line[0];
    switch (instruction)
    {
    case '#': // comment
      // skip comments
      break;
    case '@': // place
    {
      // line = "@ Apartment You are in your dingey 1 bedroom 1 bath apartment."
      int indexAfterName = line.find(" ", 2);
      string name = line.substr(2, indexAfterName - 2);
      string desc = line.substr(indexAfterName + 1);
      // save this place by name.
      places[name] = new Place(name, desc);
      // if we haven't remembered the first place yet, do it now.
      if (startPlace == nullptr)
      {
        startPlace = places[name];
      }
      // cout << "Found a place " << name << " on line " << lineNumber << endl;
    }
    break;
    case '^': // exit
    {
      // line = "^ Apartment N Hallway"
      int indexAfterName = line.find(" ", 2);
      string placeName = line.substr(2, indexAfterName - 2);
      char dir = char(tolower(line[indexAfterName + 1]));
      string destination = line.substr(indexAfterName + 3);
      // cout << "Found a direction from " << placeName << " " << dir << " to " << destination << " on line " << lineNumber << endl;

      // find the places, printing message if they aren't found.
      auto src = places[placeName];
      if (!src)
      {
        cout << "Place " << placeName << " not found for exit on line " << lineNumber << endl;
        break;
      }
      auto dst = places[destination];
      if (!dst)
      {
        cout << "Place " << destination << " not found for exit on line " << lineNumber << endl;
        break;
      }
      // cout << "Adding exit from " << placeName << " " << dir << " to " << destination << endl;

      // add the exit
      src->addExit(dir, dst);
    }
    break;
    case '$': // thing
    {
      // line = "$ Mailbox You see the mailbox"
      int indexAfterName = line.find(" ", 2);
      string name = line.substr(2, indexAfterName - 2);
      string desc = line.substr(indexAfterName + 1);
      // cout << "Found a thing " << name << " on line " << lineNumber << endl;

      // save this thing by name.
      things[name] = new Thing(name, desc);
    }
    break;
    case '!': // thing in place
    {
      // line = "! Key Hallway"
      int indexAfterName = line.find(" ", 2);
      string thingName = line.substr(2, indexAfterName - 2);
      string placeName = line.substr(indexAfterName + 1);
      // cout << "Placing " << thingName << " in " << placeName << " on line " << lineNumber << endl;

      // get the place and thing, printing message if they aren't found.
      auto place = places[placeName];
      auto thing = things[thingName];
      if (!place)
      {
        cout << "Place " << placeName << " not found for thing " << thingName << " on line " << lineNumber << endl;
        break;
      }
      if (!thing)
      {
        cout << "Thing " << thingName << " not found for place " << placeName << " on line " << lineNumber << endl;
        break;
      }
      // add the thing to the place
      place->addThing(thing);
    }
    break;

    default:
      cout << "Unknown instruction " << instruction << " on " << lineNumber << endl;
      break;
    }
  }
  // close the file
  sourceFile.close();

  // start with player in the first place we found.
  this->player = new Player(startPlace);
}

void Game::run()
{
  bool gameOver = false;
  while (!gameOver)
  {
    // cout << "You are in " << this->player->getLocation()->getName() << endl;
    cout << "> ";
    string input;
    getline(cin, input);
    if (input == "n" || input == "s" || input == "e" || input == "w")
    {
      char direction = input[0];
      if (this->player->move(direction))
      {
        cout << "You are in " << this->player->getLocation()->getName() << endl;
      }
    }
    else if (input == "q")
    {
      gameOver = true;
    }
    else if (input == "d" || input == "desc" || input == "look")
    {
      auto place = this->player->getLocation();
      cout << place->getDesc() << endl;
      auto thing = place->getThings();
      if (thing != nullptr)
      {
        cout << "You see:" << endl;
      }
      while (thing != nullptr)
      {
        cout << " " << thing->getDesc() << endl;
        thing = thing->getNextThing();
      }
    }
    else if (input.substr(0, 5) == "take ")
    {
      string thingName = to_lower(input.substr(5));
      auto place = this->player->getLocation();
      auto thing = place->getThings();
      int foundThing = 0;
      while (!foundThing && thing != nullptr)
      {
        if (to_lower(thing->getName()) == thingName)
        {
          this->player->takeThing(thing);
          cout << "You took " << thingName << endl;
          thing = nullptr;
          foundThing = 1;
        }
        else
        {
          thing = thing->getNextThing();
        }
      }
      if (!foundThing)
      {
        cout << "You don't see " << thingName << " here." << endl;
      }
    }
    else if (input.substr(0, 5) == "drop ")
    {
      string thingName = to_lower(input.substr(5));
      auto thing = this->player->getThings();
      int foundThing = 0;
      while (!foundThing && thing != nullptr)
      {
        if (to_lower(thing->getName()) == thingName)
        {
          this->player->dropThing(thing);
          cout << "You dropped " << thingName << endl;
          thing = nullptr;
          foundThing = 1;
        }
        else
        {
          thing = thing->getNextThing();
        }
      }
      if (!foundThing)
      {
        cout << "You don't have " << thingName << " on you." << endl;
      }
    }
    else if (input == "i" || input == "invent" || input == "inventory")
    {
      auto thing = this->player->getThings();
      if (thing == nullptr)
      {
        cout << "You are not carrying anything." << endl;
      }
      else
      {
        cout << "You are carrying:" << endl;
        while (thing != nullptr)
        {
          cout << " " << thing->getDesc() << endl;
          thing = thing->getNextThing();
        }
      }
    }
    else if (input == "?" || input == "help")
    {
      cout << "n, s, e, w - move in a direction" << endl;
      cout << "d, desc, look - describe the current location" << endl;
      cout << "take - take an object" << endl;
      cout << "drop - drop an object" << endl;
      cout << "i, invent, inventory - look at what you have" << endl;
      cout << "q - quit" << endl;
    }
    else
    {
      cout << "Enter a command..." << endl;
    }
  } // while !gameOver
}
