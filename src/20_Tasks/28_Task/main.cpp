#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include "../../common/math.h"
#include "../../common/primes.h"
#include "../../common/sort.h"
#include "../../common/string.h"

using namespace std;

/*
Az 1-es számmal kezdve, és jobbra haladva óramutató járásával megegyező irányban egy 5×5-ös spirál jön létre az alábbi módon:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

Igazolható, hogy az átlókon lévő számok összege 101.

Mennyi az átlókon lévő számok összege egy ugyanilyen módon létrehozott 1001×1001-es spirálban?

*/

int main()
{
  const int n = 1001;
  long long result = 1;
  int num = 1;
  int add = 2;

  while (num < (n * n))
  {
    for (int i = 0; i < 4; i++)
    {
      num += add;
      result += num;  
    }

    add += 2;
  }

  cout << "Result: " << result << std::endl;
  return 0;
}
