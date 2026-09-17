#include <iostream>
#include "../common/math.h"
using namespace std;

/*
Egy szám tökéletes szám, ha valódi osztóinak összege pontosan egyenlő magával a számmal.
Például a 28 valódi osztóinak összege 1 + 2 + 4 + 7 + 14 = 28, tehát a 28 tökéletes szám.

Egy n számot hiányosnak nevezünk, ha valódi osztóinak összege kisebb, mint n, és bővelkedőnek, ha ez az összeg meghaladja n-et.

Mivel 12 a legkisebb bővelkedő szám (1 + 2 + 3 + 4 + 6 = 16), a legkisebb szám, amely felírható két bővelkedő szám összegeként, a 24.
Matematikai elemzéssel kimutatható, hogy minden 28123-nál nagyobb egész szám felírható két bővelkedő szám összegeként.
Ez a felső korlát azonban elemzéssel tovább nem csökkenthető, jóllehet ismert, hogy a legnagyobb szám,
amely nem fejezhető ki két bővelkedő szám összegeként, ennél a korlátnál kisebb.

Határozd meg az összes olyan pozitív egész szám összegét, amely nem írható fel két bővelkedő szám összegeként.
*/

int main()
{
  const int LIMIT = 28123;
  set<int> numbers;

  long long result = 0;

  for (size_t i = 12; i < LIMIT; i++)
  {
    if (sum(trueDividers(i)) > i)
      numbers.insert(i);
  }

  for (size_t i = 0; i <= LIMIT; i++)
  {
    bool good = true;
    for (auto &&num : numbers)
    {
      if (numbers.find(i - num) != numbers.end())
      {
        good = false;
        break;
      }
    }

    if (good)
      result += i;
  }

  cout << "Result: " << result;
  return 0;
}
