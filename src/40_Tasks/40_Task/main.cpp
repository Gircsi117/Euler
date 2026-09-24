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
Egy irracionális tizedestört jön létre a pozitív egész számok egymás mögé írásával:

0,123456789101112131415161718192021…

Látható, hogy a törtrész 12. számjegye 1.

Ha dₙ a törtrész n. számjegyét jelöli, határozd meg a következő kifejezés értékét:

d₁ × d₁₀ × d₁₀₀ × d₁₀₀₀ × d₁₀₀₀₀ × d₁₀₀₀₀₀ × d₁₀₀₀₀₀₀


*/

set<int> ds = {};
map<int, int> values = {};

int euler(int n)
{
  if (n <= 9)
    return n;

  return -1;
}

int main()
{

  for (int i = 0; i < 7; i++)
  {
    int value = ceil(pow(10, float(i)));
    values[i] = 9 * (i + 1) * value;
    ds.insert(value);

    cout << values[i] << "\n";
  }

  for (auto &&i : ds)
  {
    cout << "d_" << i << " = " << euler(i) << std::endl;
  }

  cout << "Result: " << pow(10, 2) << std::endl;
  return 0;
}
