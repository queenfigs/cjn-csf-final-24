// Copyright © 2024 - Cleo Naughton

#include <locale>

#include "to_lower.h"

string to_lower(string s)
{
  for (char &c : s)
    c = tolower(c);
  return s;
}