#include <iostream>
#include <cmath>
#include "../common/primes.h"
using namespace std;

/*
A háromszögszámok sorozata a természetes számok összeadásával jön létre. Tehát a 7. háromszögszám

1+2+3+4+5+6+7=28 lenne. Az első tíz tag a következő lenne:

1,3,6,10,15,21,28,36,45,55,…

Soroljuk fel az első hét háromszögszám osztóit:

1   : 1
3   : 1, 3
6   : 1, 2, 3, 6
10  : 1, 2, 5, 10
15  : 1, 3, 5, 15
21  : 1, 3, 7, 21
28  : 1, 2, 4, 7, 14, 28

Láthatjuk, hogy 28 az első háromszögszám, aminek több mint öt osztója van.

Mennyi az első háromszögszám értéke, aminek több mint ötszáz osztója van?
*/

const int LIMIT = 500;

int main()
{
  long long n = 1;

  while (true)
  {
    long long number = (n * (n + 1)) / 2;
    vector<long long> dividers = primeFactorization(number);

    int trueDividerCount = 1;

    int count = 1;

    for (int i = 0; i < dividers.size(); i++)
    {
      if (i == dividers.size() - 1)
      {
        trueDividerCount *= count + 1;
        break;
      }

      if (dividers[i] == dividers[i + 1])
      {
        count++;
      }
      else
      {
        trueDividerCount *= count + 1;
        count = 1;
      }
    }

    if (trueDividerCount >= LIMIT)
    {
      cout << n << ". => " << number << " => " << trueDividerCount << "\n";
      break;
    }

    n++;
  }
  
  return 0;
}
