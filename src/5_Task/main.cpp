#include <iostream>
#include <cmath>
using namespace std;

/*
A 2520 a legkisebb olyan szám, amely 1-től 10-ig minden számmal maradék nélkül osztható.

Mi a legkisebb pozitív szám, amely 1-től 20-ig minden számmal maradék nélkül osztható?
*/

bool is_prim(long long num)
{
  for (long long i = 2; i <= ceil(num / 2); i++)
  {
    if (num % i == 0)
      return false;
  }

  return true;
}

int main()
{
  int max = 20;

  long long num = 1;

  for (int i = 2; i <= max; i++)
  {
    if (is_prim(i))
    {
      int x = i;

      while (x < max)
      {
        int y = x * i;
        if (y < max)
          x = y;
        else
          break;
      }

      cout << to_string(i) + " => " + to_string(x) + "\n";
      num *= x;
    }
  }

  cout << "The smallest number is: " + to_string(num);
  return 0;
}
