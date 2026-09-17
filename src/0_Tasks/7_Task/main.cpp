#include <iostream>
#include <cmath>
#include "../common/primes.h"
using namespace std;

/*
Az első hat prímszámot felsorolva: 2, 3, 5, 7, 11 és 13, láthatjuk, hogy a 6. prím a 13.

Mi a 10001. prímszám?
*/

int main()
{
  int goal = 10001;
  int count = 0;

  int num = 1;

  while (count != goal)
  {
    num++;

    if (isPrime(num))
    {
      count++;
    }
  }

  cout << "The prim number is: " + to_string(num);
  return 0;
}
