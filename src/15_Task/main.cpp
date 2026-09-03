#include <iostream>
#include "../common/math.h"
using namespace std;

/*
Egy 2×2-es rács bal felső sarkából indulva, és csak jobbra vagy lefelé mozogva, pontosan 6 útvonal vezet a jobb alsó sarokba.

Hány ilyen útvonal van egy 20×20-as rácson keresztül?

Megjegyzések:
Egy n*n-es mezőben n-szer megyünk jobbra és n-szer le. A feladat, hogy ezeket hány féle képpen lehet egymás után helyezni.

egy nxn-es területen n lépést mehetünk jobbra és n lépést mehetünk lefelé

n alatt a k -> (n!)/(k! * (n-k)!)

1 x 2 x 3 x 4 x 5 x 6 x 7 x 8 x 9 x 10
---------------------------------------
1 x 2 x 3 x 4 x 5 x (1 x 2 x 3 x 4 x 5)

6 x 7 x 8 x 9 x 10
------------------
1 x 2 x 3 x 4 x 5
*/

const int SIZE = 20;

int main()
{
  double result = 1.0;

  for (double i = 1; i <= SIZE; i++)
  {
    //cout << SIZE + i << " / " << i << "\n";
    result *= (SIZE + i) / i;
  }

  cout << "Result: " << to_string(result) << "\n";
  return 0;
}
