#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

inline vector<string> split(const string &s, char delimiter)
{
  vector<string> tokens;
  stringstream ss(s);
  string token;
  while (getline(ss, token, delimiter))
  {
    tokens.push_back(token);
  }
  return tokens;
}

inline string longest(const vector<string> &words)
{
  string longestStr = "";

  for (auto &&word : words)
  {
    if (word.length() > longestStr.length())
      longestStr = word;
  }

  return longestStr;
}