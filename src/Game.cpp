// Copyright © 2024 - Cleo Naughton

#include <string>
#include <iostream>
#include <map>
#include <fstream>

#include "Game.h"
#include "Place.h"
#include "Player.h"

using namespace std;

Game::Game(string filename)
{
  cout << "Game constructor called with " << filename << endl;

  ifstream sourceFile(filename);
  // check to see if it the file was opened.
  if (sourceFile.is_open())
  {
    cout << "Loading game from " << filename << "..." << endl;
  }
  else
  {
    // print file not found message and exit.
    cout << "File named " << filename << " does not exist." << endl;
    exit(1);
  }

  // store map from place names to places.
  map<string, Place *> places;
  string line;
  int lineNumber = 0;
  while (getline(sourceFile, line))
  {
    lineNumber++;
    if (line.length() == 0)
    {
      // skip empty lines
      continue;
    }
    char instruction = line[0];
    switch (instruction)
    {
    case '#':
      // skip comments
      break;
    case '@':
    {
      // line = "@ Apartment You are in your dingey 1 bedroom 1 bath apartment."
      int indexAfterName = line.find(" ", 2);
      string name = line.substr(2, indexAfterName - 2);
      string desc = line.substr(indexAfterName + 1);
      // save this place by name.
      places[name] = new Place(name, desc);
      cout << "Found a place " << name << " on line " << lineNumber + 1 << endl;
    }
    break;
    case '^':
    {
      // line = "^ Apartment N Hallway"
      int indexAfterName = line.find(" ", 2);
      string placeName = line.substr(2, indexAfterName - 2);
      char dir = char(tolower(line[indexAfterName + 1]));
      string destination = line.substr(indexAfterName + 3);
      cout << "Found a direction from " << placeName << " " << dir << " to " << destination << " on line " << lineNumber + 1 << endl;

      // find the places
      auto src = places[placeName];
      auto dst = places[destination];
      // add the exit
      src->addExit(dir, dst);
    }
    break;

    default:
      cout << "Unknown instruction " << instruction << " on " << lineNumber << endl;
      break;
    }
  }
  // close the file
  sourceFile.close();

  // hack we will decide what is the starting place later.
  this->player = new Player(places["Apartment"]);
}

void Game::run()
{
  cout << "Game run() called" << endl;

  bool gameOver = false;
  while (!gameOver)
  {
    cout << "You are in " << this->player->getLocation()->getName() << endl;
    cout << "Where would you like to go? (N, S, E, W, Q)" << endl;
    char direction;
    cin >> direction;
    switch (char(tolower(direction)))
    {
    case 'n':
    case 's':
    case 'e':
    case 'w':
      this->player->move(direction);
      break;
    case 'q':
      gameOver = true;
      break;
    case 'd':
      cout << this->player->getLocation()->getDesc() << endl;
      break;
    default:
      cout << "N: North, S: South, E: East, W: West, Q: Quit" << endl;
    }
  }
}