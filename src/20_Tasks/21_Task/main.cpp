#include <iostream>
#include "../../common/math.h"
using namespace std;

/*
Legyen d(n) az n szám valódi osztóinak összege (azok a számok, amelyek n-nél kisebbek, és maradék nélkül osztják n-et).

Ha d(a) = b és d(b) = a, ahol a ≠ b, akkor a és b egy barátságos számpárt alkotnak, és a-t, illetve b-t barátságos számoknak nevezzük.

Például: 220 valódi osztói 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 és 110; tehát d(220) = 284. A 284 valódi osztói 1, 2, 4, 71 és 142; tehát d(284) = 220.

Határozd meg a 10000 alatti összes barátságos szám összegét.
*/

int main()
{
  set<int> friends = {};

  for (int num = 220; num <= 10000; num++)
  {
    if (friends.find(num) != friends.end())
      continue;

    set<int> items = trueDividers(num);
    items.erase(num);

    int summary = sum(items);
    set<int> items2 = trueDividers(summary);
    items2.erase(summary);

    int summary2 = sum(items2);
    if (summary2 == num && num != summary)
    {
      friends.insert(num);
      friends.insert(summary2);
    }
  }

  cout << "Result: " << sum(friends);
  return 0;
}
