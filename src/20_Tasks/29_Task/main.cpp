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
Tekintsük az aᵇ összes egész szám kombinációját, ahol 2 ≤ a ≤ 5 és 2 ≤ b ≤ 5:

2² = 4, 2³ = 8, 2⁴ = 16, 2⁵ = 32
3² = 9, 3³ = 27, 3⁴ = 81, 3⁵ = 243
4² = 16, 4³ = 64, 4⁴ = 256, 4⁵ = 1024
5² = 25, 5³ = 125, 5⁴ = 625, 5⁵ = 3125

Ha ezeket számsorrendbe rendezzük, az ismétlődéseket eltávolítva, a következő 15 különböző tagból álló sorozatot kapjuk:

4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125.

Hány különböző tag van az aᵇ által generált sorozatban, ha 2 ≤ a ≤ 100 és 2 ≤ b ≤ 100?

Result: 9183
*/

string euler(int a, int b)
{
  string result = "1";

  for (int i = 0; i < b; i++)
  {
    result = multiplication(result, a);
  }

  return result;
}

int main()
{
  set<string> result = {};

  for (int a = 2; a <= 100; a++)
  {
    string res = to_string(a);

    for (int b = 2; b <= 100; b++)
    {
      res = multiplication(res, a);
      result.insert(res);

      //cout << a << "^" << b << " = " << res << "\n";
    }
  }

  cout << "Result: " << result.size() << std::endl;
  return 0;
}
