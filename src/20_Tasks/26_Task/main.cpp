#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#include "../common/math.h"
#include "../common/primes.h"
#include "../common/sort.h"
#include "../common/string.h"

using namespace std;

/*
Egy egységtört a számlálóban 1-et tartalmaz. A 2-től 10-ig terjedő nevezőjű egységtörtek decimális alakja:

1/2 = 0,5
1/3 = 0,(3)
1/4 = 0,25
1/5 = 0,2
1/6 = 0,1(6)
1/7 = 0,(142857)
1/8 = 0,125
1/9 = 0,(1)
1/10 = 0,1

Ahol a 0,1(6) azt jelenti: 0,166666…, és ennek 1 számjegyből álló szakasza ismétlődik (periodikus rész).
Látható, hogy az 1/7-nek 6 számjegyből álló ismétlődő szakasza van.

Határozd meg azt a d < 1000 értéket, amelyre az 1/d a leghosszabb periodikus szakaszt tartalmazza a decimális tört részében.
*/

int main()
{
  string longestNumber = "";
  int result = 0;

  for (size_t d = 2; d < 1000; d++)
  {
    int rest = 1;
    string number = "";
    set<int> rests;

    while (rest != 0)
    {
      rest *= 10;

      int count = rest / d;
      rest %= d;

      if (rests.find(rest) != rests.end())
      {
        //cout << d << " Repeat: " << number << "\n";

        if (number.length() > longestNumber.length())
        {
          longestNumber = number;
          result = d;
        }

        break;
      }

      rests.insert(rest);
      number += to_string(count);
    }
  }

  cout << "Length: " << longestNumber.length() << "\n";
  cout << "Result: " << result << "\n";

  return 0;
}
