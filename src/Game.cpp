// Copyright © 2024 - Cleo Naughton

#include <string>
#include <iostream>
#include <map>
#include <fstream>

#include "Game.h"
#include "Place.h"

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
      // save this place by name.
      places[name] = new Place(name);
      cout << "Found a place " << name << " on line " << lineNumber + 1 << endl;
    }
    break;
    case '^':
    {
      // line = "^ Apartment N Hallway"
      int indexAfterName = line.find(" ", 2);
      string placeName = line.substr(2, indexAfterName - 2);
      char dir = line[indexAfterName + 1];
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
}

void Game::run()
{
  cout << "Game run() called" << endl;
}