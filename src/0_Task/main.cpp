#include <iostream>
using namespace std;

/*
Egy szám négyzetszám, ha egy pozitív egész szám négyzete. Például a 25 négyzetszám, mert 5² = 5×5 = 25; egyben páratlan négyzetszám is.
Az első 5 négyzetszám: 1, 4, 9, 16, 25, és a páratlan négyzetszámok összege 1+9+25 = 35.

Az első 955 ezer négyzetszám közül mennyi az összes páratlan négyzetszám összege?
*/

int main()
{
  int max = 955000;
  long long sum = 0;

  for (int i = 1; i <= max; i += 2)
  {
    sum += (long long)i * i;
  }

  cout << "The summary is: " + to_string(sum);

  return 0;
}