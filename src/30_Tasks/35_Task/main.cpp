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
A 197 számot körkörös prímnek nevezzük, mert a számjegyeinek összes forgatása: 197, 971 és 719 is prímszám.

Százon belül tizenhárom ilyen prím van: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79 és 97.

Hány körkörös prím van egymillió alatt?

Result: 55
*/

set<int> tested = {};

int euler(int num)
{
  string strNum = to_string(num);

  if (tested.find(num) != tested.end())
    return 0;

  set<int> numbers = {};

  for (int i = 0; i < strNum.length(); i++)
  {
    int n = stoi(strNum);

    if (!isPrime(n))
      return 0;

    numbers.insert(n);
    tested.insert(n);
    strNum = strNum.substr(1, strNum.length()) + strNum[0];
  }

  return numbers.size();
}

int main()
{
  int result = 0;

  for (size_t i = 2; i < 1000000; i++)
  {
    result += euler(i);
  }

  cout << "Result: " << result << std::endl;
  return 0;
}
