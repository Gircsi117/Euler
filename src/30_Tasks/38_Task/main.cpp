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
Vedd a 192 számot, és szorozd meg mindegyikkel: 1, 2 és 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576

A szorzatok egymás után fűzésével megkapjuk az 1-től 9-ig pandigitális 192384576 számot.
A 192384576 számot a 192 és (1, 2, 3) összefűzött szorzatának nevezzük.

Ugyanez elérhető úgy is, hogy 9-cel kezdünk, és 1-gyel, 2-vel, 3-mal, 4-gyel és 5-tel szorozzuk,
ami a pandigitális 918273645-öt adja, amely a 9 és (1, 2, 3, 4, 5) összefűzött szorzata.

Mi a legnagyobb 1-től 9-ig pandigitális 9-jegyű szám, amely előállítható egy egész szám és (1, 2, ..., n) összefűzött szorzataként, ahol n > 1?

Result: 932718654
*/

long long euler(int num)
{
  string result = to_string(num);

  if (result.length() >= 9)
    return -1;

  int n = 2;

  while (result.length() < 9)
  {
    result += to_string(num * n);
    n++;
  }

  if (result.length() > 9 && n == 3)
    return -1;

  if (result.length() > 9)
    return 0;

  return stoll(result);
}

int main()
{

  long long max = 0;

  long long n = 1;

  while (true)
  {
    long long result = euler(n);
    if (result == -1)
      break;

    if (result > 0 && result > max && isPandigital(result))
    {
      cout << result << "\n";
      max = result;
    }

    n++;
  }

  cout << "Result: " << max << std::endl;
  return 0;
}
