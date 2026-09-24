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
A 3797 számnak érdekes tulajdonsága van. Mivel önmaga prím, folyamatosan eltávolíthatók a számjegyei balról jobbra haladva úgy,
hogy minden lépésben prím marad: 3797, 797, 97 és 7. Hasonlóképpen jobbról balra is működik: 3797, 379, 37 és 3.

Határozd meg annak a mindössze tizenegy prímnek az összegét, amelyek balról jobbra és jobbról balra is csonkolhatók.

MEGJEGYZÉS: A 2, 3, 5 és 7 nem tekinthetők csonkolható prímeknek.
*/

bool euler(int n)
{
  string s = to_string(n);

  for (int i = 1; i < s.length(); i++)
  {
    string left = s.substr(i, s.length());
    string right = s.substr(0, s.length() - i);

    if (!isPrime(stoi(left)) || !isPrime(stoi(right)))
      return false;
  }

  return true;
}

int main()
{

  set<int> primes = {};

  int n = 11;
  while (primes.size() < 11)
  {
    if (isPrime(n) && euler(n))
      primes.insert(n);

    n++;
  }

  cout << "Result: " << sum(primes) << std::endl;
  return 0;
}
