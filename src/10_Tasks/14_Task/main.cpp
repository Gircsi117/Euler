#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
A következő iteratív sorozat van definiálva a pozitív egész számok halmazára:

n → n/2 (ha n páros)
n → 3n + 1 (ha n páratlan)

A fenti szabályt használva és 13-mal kezdve a következő sorozatot kapjuk:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1.

Látható, hogy ez a sorozat (13-mal kezdve és 1-nél végződve) 10 tagot tartalmaz. Bár még nincs bebizonyítva (Collatz-probléma),
azt gondolják, hogy minden kezdőszám 1-nél végződik.

Melyik egymillió alatti kezdőszám állítja elő a leghosszabb láncot?

MEGJEGYZÉS: Ha a lánc elindult, a tagok már meghaladhatják az egymilliót.

Result: 837799
*/

map<int, int> dict = {};

int collatz(long long n)
{
  if (dict.find(n) != dict.end())
  {
    return dict[n];
  }

  int count = 1;

  if (n % 2 == 0)
  {
    count = 1 + collatz(n / 2);
  }
  else
  {
    count = 1 + collatz(3 * n + 1);
  }

  dict[n] = count;
  return count;
}

int main()
{
  dict[1] = 1;
  const int START_N = 13;
  const int MAX_N = 1000000;

  int result = 0;
  int count = 0;

  for (int i = START_N; i < MAX_N; i++)
  {
    int a = collatz(i);

    if (a > count)
    {
      count = a;
      result = i;
    }

    //cout << i << " => " << a << "\n";
  }

  cout << "Result: " << result << "\n";
  return 0;
}
