// Copyright © 2024 - Cleo Naughton

#include "Place.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Place::Place(string name)
{
    cout << "Place constructor called with " << name << endl;
    this->name = name;
}