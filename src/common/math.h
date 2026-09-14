#pragma once
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

inline int digitSum(string number)
{
  int result = 0;

  for (int i = 0; i < number.length(); i++)
  {
    result += stoi(number.substr(i, 1));
  }

  return result;
}