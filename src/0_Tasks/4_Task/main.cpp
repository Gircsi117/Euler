#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
A palindrom szám mindkét irányból ugyanúgy olvasható. A legnagyobb palindrom szám, amely két kétjegyű szám szorzataként áll elő, a 9009 = 91 × 99.

Határozd meg a legnagyobb palindrom számot, amely két háromjegyű szám szorzataként áll elő.
*/

bool isPalindrom(int num)
{
  string original = to_string(num);
  string reversed = to_string(num);

  reverse(reversed.begin(), reversed.end());

  return original == reversed;
}

int main()
{
  int firs = 999;
  int second = 999;

  long long max = 0;

  while (firs > 99 && second > 99)
  {
    long long num = (long long)firs * second;

    if (isPalindrom(num) && num > max)
      max = num;

    firs--;
    if (firs < 100)
    {
      firs = 999;
      second--;
    }
  }

  cout << "The greatest palindrom: " + to_string(max);
  return 0;
}
