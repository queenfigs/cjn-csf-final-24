// Copyright © 2024 - Cleo Naughton

#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>

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

  string line;
  int lineNumber = 0;
  while (getline(sourceFile, line))
  {
    lineNumber++;
  }
  cout << "Read " << lineNumber << " lines from " << filename << endl;

  // close the file
  sourceFile.close();
}

void Game::run()
{
  cout << "Game run() called" << endl;
}