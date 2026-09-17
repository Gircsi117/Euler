#include <iostream>
#include "../common/primes.h"
using namespace std;

/*
A 10 alatti prímek összege 2 + 3 + 5 + 7 = 17.

Határozd meg a kétmillió alatti összes prím összegét.
*/

int main()
{
  long long result = 0;

  for (int i = 2; i < 2000000; i++)
  {
    if (isPrime(i))
    {
      result += i;
    }
  }

  cout << "Result: " << result << "\n";
  return 0;
}
