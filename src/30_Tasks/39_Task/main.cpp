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
Ha p egy olyan derékszögű háromszög kerülete, amelynek oldalhosszai egész számok,
{a, b, c}, akkor p = 120 esetén pontosan három megoldás van.

{20, 48, 52}, {24, 45, 51}, {30, 40, 50}

Mely p ≤ 1000 érték esetén maximális a megoldások száma?

a^2 + b^2 = c^2
*/

int euler(int K)
{
  int count = 0;

  float a = 2;
  float b = 2;

  while (a + b < K)
  {
    float c = sqrt(a * a + b * b);

    if (b + c == K - a)
      count++;

    b++;
    if (a + b + c > K)
    {
      a++;
      b = a;
    }
  }

  return count;
}

int main()
{
  int result = 0;
  int max = 0;

  for (int i = 5; i <= 1000; i++)
  {
    int count = euler(i);
    if (count > max)
    {
      max = count;
      result = i;
    }
  }

  cout << "Result: " << result << std::endl;
  return 0;
}
