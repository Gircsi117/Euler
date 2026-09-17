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
  // int num = 13195;
  long long num = 600851475143;

  vector<long long> dividers = primeFactorization(num);

  for (int d : dividers)
  {
    cout << d << "\n";
  }

  return 0;
}
