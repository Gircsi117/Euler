#include <iostream>
#include <cmath>
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

  long long number = 1;
  int n = 0;

  while (true)
  {
    number = (n * (n + 1)) / 2;

    cout << number << "\n";

    n++;
  }

  cout << "Result: " << number << "\n";
  return 0;
}
