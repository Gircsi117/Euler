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
A 585 = 1001001001₂ (binárisan) decimális szám mindkét számrendszerben palindrom.

Határozd meg az összes olyan egymilliónál kisebb szám összegét, amely 10-es és 2-es számrendszerben is palindrom.

(Vedd figyelembe, hogy a palindrom szám egyik számrendszerben sem tartalmazhat vezető nullát.)

Result: 872187
*/

string toBinary(int num)
{
  if (num == 0)
    return "0";

  string result = "";

  while (num > 0)
  {
    int bin = num % 2;

    result = to_string(bin) + result;

    num /= 2;
  }

  return result;
}

int main()
{
  int result = 0;

  for (int i = 1; i < MILLION; i++)
  {
    if (!isPalindrom(to_string(i)))
      continue;

    string bin = toBinary(i);

    if (bin[0] != '0' && isPalindrom(bin))
    {
      result += i;
      cout << i << "\n";
    }
  }

  cout << "Result: " << result << std::endl;
  return 0;
}
