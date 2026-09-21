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
A 49/98 törtnek van egy furcsa tulajdonsága: egy tapasztalatlan matematikus, aki megpróbálja egyszerűsíteni,
tévesen azt hiheti, hogy 49/98 = 4/8, ami — bár helyes — a 9-esek egyszerű kihúzásával jön ki.

Az olyan törteket, mint a 30/50 = 3/5, triviális példáknak tekintjük.

Pontosan négy nemtriviális példa van ilyen típusú törtből, amelyek értéke egynél kisebb, és a számláló, illetve a nevező kétjegyű.

Ha ennek a négy törtnek a szorzatát a legegyszerűbb alakjában adjuk meg, határozd meg a nevező értékét.
*/

bool euler(float a, float b)
{
  if (int(a) % 10 == 0 || int(b) % 10 == 0)
    return false;

  string sa = to_string(a).substr(0, 2);
  string sb = to_string(b).substr(0, 2);

  for (auto &&i : sa)
  {
    if (sb.find(string() + i) != string::npos)
    {
      float fa = stof(replaceFirst(sa, string() + i, ""));
      float fb = stof(replaceFirst(sb, string() + i, ""));

      if (fa / fb == a / b)
        return true;
    }
  }

  return false;
}

int main()
{
  float a = 10;
  float b = 11;

  long long aa = 1;
  long long bb = 1;

  while (a <= 99 && b <= 99)
  {

    if (euler(a, b))
    {
      aa *= a;
      bb *= b;
      cout << a << " / " << b << "\n";
    }

    a++;
    if (a == 100 || a >= b)
    {
      a = 11;
      b++;
    }
  }

  cout << "\n"
       << aa << " / " << bb << "\n";

  set<int> div_aa = dividers(aa);
  set<int> div_bb = dividers(bb);

  vector<int> check = {div_aa.begin(), div_aa.end()};

  for (int i = check.size() - 1; i >= 0; i--)
  {
    if (div_bb.find(check[i]) != div_bb.end())
    {
      cout << "Result: " << bb / check[i] << std::endl;
      return 0;
    }
  }

  return 0;
}
