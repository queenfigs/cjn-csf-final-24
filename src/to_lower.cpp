// Copyright © 2024 - Cleo Naughton

#include <locale>

#include "to_lower.h"

// lowercases strings.
// Turns "HElLo WOrLd" -> "hello world"
string to_lower(string s)
{
  // Get a pointer to each char in s
  for (char &c : s)
  {
    // write the lowercase letter back into s
    c = tolower(c);
  }
  // return string lowercased
  return s;
}