#pragma once

#include <iostream>
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

inline string replaceFirst(string word, string replaced, string sub)
{
  int index = word.find(replaced);
  if (index == string::npos)
    return word;

  return word.replace(index, replaced.length(), sub);
}

inline string replaceAll(string word, string replaced, string sub)
{
  string result = word;
  int index = 0;

  while (result.find(replaced) != string::npos)
  {
    result = replaceFirst(result, replaced, sub);
  }

  return result;
}

inline bool isPalindrom(string word)
{
  string w = word;
  reverse(w.begin(), w.end());

  return w == word;
}