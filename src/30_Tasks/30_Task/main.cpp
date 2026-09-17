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
Meglepő módon csak három olyan szám van, amely felírható a számjegyeinek negyedik hatványainak összegeként:

1634 = 1⁴ + 6⁴ + 3⁴ + 4⁴
8208 = 8⁴ + 2⁴ + 0⁴ + 8⁴
9474 = 9⁴ + 4⁴ + 7⁴ + 4⁴

Mivel 1 = 1⁴ nem tekinthető összegnek, ezért nem szerepel a felsorolásban.

Ezeknek a számoknak az összege 1634 + 8208 + 9474 = 19316.

Határozd meg az összes olyan szám összegét, amely felírható a számjegyeinek ötödik hatványainak összegeként.
*/
map<int, int> help = {};
const int n = 5;

int euler(int a)
{
  string num = to_string(a);

  int result = 0;

  for (auto &&i : num)
  {
    result += help[stoi(string() + i)];
  }

  return result;
}

int main()
{
  for (int i = 0; i < 10; i++)
  {
    help[i] = stoi(pow(i, n));
  }

  string result = "0";

  for (int i = 2; i < 1000000; i++)
  {
    int num = euler(i);
    if (num == i)
    {
      result = sum(vector<string>{result, to_string(num)});
    }
  }

  cout << "Result: " << result << std::endl;
  return 0;
}
