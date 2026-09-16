#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include "../common/math.h"
#include "../common/primes.h"
#include "../common/sort.h"
#include "../common/string.h"

using namespace std;

/*
Euler felfedezte a figyelemre méltó másodfokú képletet:

n² + n + 41

Kiderül, hogy ez a képlet 40 prímszámot ad a 0 ≤ n ≤ 39 egymást követő egész értékekre.
Azonban n = 40 esetén 40² + 40 + 41 = 40(40 + 1) + 41 osztható 41-gyel, és n = 41 esetén 41² + 41 + 41 nyilvánvalóan osztható 41-gyel.

Felfedezték a hihetetlen n² − 79n + 1601 képletet, amely 80 prímszámot ad a 0 ≤ n ≤ 79 egymást követő értékekre.
Az együtthatók szorzata, −79 és 1601, −126479.

Tekintsük a következő alakú másodfokú kifejezéseket:

n² + an + b, ahol |a| < 1000 és |b| ≤ 1000

ahol |n| az n modulusa/abszolút értéke,
pl. |11| = 11 és |−4| = 4

Határozd meg az a és b együtthatók szorzatát arra a másodfokú kifejezésre, amely a legtöbb prímszámot adja egymást követő n értékekre, n = 0-tól kezdve.
*/

int main()
{
  cout << "Result: " << "0" << "\n";
  return 0;
}
