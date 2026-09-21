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
Azt mondjuk, hogy egy n-jegyű szám pandigitális, ha az 1-től n-ig terjedő számjegyek mindegyikét pontosan egyszer használja fel;
például az 5-jegyű 15234 szám 1-től 5-ig pandigitális.

A 7254 szorzat szokatlan, mivel a 39 × 186 = 7254 azonosság, amely a szorzandót, a szorzót és a szorzatot tartalmazza, 1-től 9-ig pandigitális.

Határozd meg az összes olyan szorzat összegét, amelynek szorzandó/szorzó/szorzat azonossága felírható 1-től 9-ig pandigitálisként.

TIPP: Néhány szorzat többféleképpen is előállítható, ezért ügyelj arra, hogy az összegedben csak egyszer szerepeljen.
*/

bool euler(string str)
{
  set<string> chars = {};

  for (auto &&i : str)
  {
    string c = string() + i;
    if (c == "0")
      return false;
    chars.insert(c);
  }

  return chars.size() == 9;
}

int main()
{
  int a = 2;
  int b = 1;

  int fails = 0;

  set<string> result = {};

  while (fails < 5)
  {
    int c = a * b;

    string str = to_string(a) + to_string(b) + to_string(c);

    if (str.length() > 9)
    {
      fails++;
      a++;
      b = 1;
      continue;
    }
    fails = 0;

    if (str.length() == 9 && euler(str))
    {
      result.insert(to_string(c));
    }

    b++;
  }

  cout << "Result: " << sum(vector<string>(result.begin(), result.end())) << std::endl;
  return 0;
}
