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
145 egy furcsa szám, mivel 1! + 4! + 5! = 1 + 24 + 120 = 145.

Határozd meg az összes olyan szám összegét, amely egyenlő a számjegyei faktoriálisainak összegével.

Megjegyzés: Mivel 1! = 1 és 2! = 2 nem összegek, ezért ezek nem tartoznak bele.

Result: 40730
*/

map<char, int> factorials = {};

bool euler(int num)
{
  string strNum = to_string(num);
  long long result = 0;

  for (auto &&i : strNum)
  {
    result += factorials[i];

    if (result > num)
      return false;
  }

  return result == num;
}

int main()
{
  long long result = 0;

  for (int i = 0; i < 10; i++)
  {
    factorials[to_string(i)[0]] = factorial(i);
  }

  for (size_t i = 3; i < 1000000; i++)
  {
    if (euler(i))
      result += i;
  }

  cout << "Result: " << result << std::endl;
  return 0;
}
