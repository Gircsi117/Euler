#include <iostream>
#include <cmath>
#include "../common/primes.h"
using namespace std;

/*
A 13195 prímtényezői: 5, 7, 13 és 29.

Mi a 600851475143 szám legnagyobb prímtényezője?
*/

int main()
{
  //int num = 13195;
  long long num = 600851475143;

  long long maxPrim = 1;

  if (isPrime(num))
    cout << "The max prim is:" + to_string(num);

  while (num != 1)
  {
    if (isPrime(num))
    {
      if (num > maxPrim)
        maxPrim = num;
      break;
    }

    for (long long i = 2; i < ceil(num / 2); i++)
    {
      if (!isPrime(i))
        continue;

      if (num % i == 0)
      {
        num /= i;

        if (i > maxPrim)
          maxPrim = i;
      }
    }
  }

  cout << "The greatest prim is:" + to_string(maxPrim);
  return 0;
}
