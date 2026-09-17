#pragma once

#include <cmath>
#include <vector>
#include <set>
#include "string.h"

using namespace std;

inline long long factorial(long long num)
{
  long long result = 1;
  for (long long i = 1; i <= num; i++)
  {
    result *= i;
  }
  return result;
}

inline string multiplication(string number, int product)
{
  string current = "";
  int rest = 0;

  for (int i = number.length() - 1; i >= 0; i--)
  {
    int num = stoi(number.substr(i, 1)) * product + rest;

    string numStr = to_string(num);

    if (i == 0)
    {
      current = numStr + current;
      continue;
    }

    string last = numStr.substr(numStr.length() - 1, 1);

    current = last + current;

    string r = numStr.substr(0, numStr.length() - 1);
    if (r == "")
    {
      rest = 0;
    }
    else
    {
      rest = stoi(r);
    }
  }

  return current;
}

inline int sum(string number)
{
  int result = 0;

  for (int i = 0; i < number.length(); i++)
  {
    result += stoi(number.substr(i, 1));
  }

  return result;
}

inline int sum(set<int> numbers)
{
  int result = 0;

  for (auto number : numbers)
  {
    result += number;
  }

  return result;
}

inline string sum(const vector<string> &numbers)
{
  string result = "";
  int rest = 0;

  string longestNum = longest(numbers);

  for (int i = 0; i < longestNum.length(); i++)
  {
    int current = 0;

    for (string number : numbers)
    {
      int index = number.length() - (i + 1);

      if (index >= 0)
        current += stoi(number.substr(index, 1));
    }

    current += rest;

    string currentStr = to_string(current);

    string value = currentStr.substr(currentStr.length() - 1, 1);
    result = value + result;

    currentStr.pop_back();
    if (currentStr.length() == 0)
    {
      rest = 0;
    }
    else
    {
      rest = stoi(currentStr);
    }
  }

  if (rest > 0)
    return to_string(rest) + result;

  return result;
}

inline set<int> dividers(int number)
{
  set<int> dividers = {1, number};

  for (int i = 2; i <= ceil(sqrt(number)); i++)
  {
    if (number % i == 0)
    {
      dividers.insert(i);
      dividers.insert(number / i);
    }
  }

  return dividers;
}

inline set<int> trueDividers(int number)
{
  set<int> results = dividers(number);
  results.erase(number);

  return results;
}

inline string pow(int a, int b)
{
  if (a == 0)
    return "0";

  string result = "1";

  for (int i = 0; i < b; i++)
  {
    result = multiplication(result, a);
  }

  return result;
}