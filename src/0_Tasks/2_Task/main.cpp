#include <iostream>
using namespace std;

/*
A Fibonacci-sorozat minden új tagját úgy kapjuk, hogy összeadjuk az előző két tagot. Ha 1-gyel és 2-vel kezdünk, az első 10 tag a következő:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

Vizsgáld meg a Fibonacci-sorozat azon tagjait, amelyek értéke nem haladja meg a négymilliót, és határozd meg a páros értékű tagok összegét.
*/

int main()
{
  int first = 1;
  int second = 1;
  int sum = 0;

  while (second < 4000000)
  {
    int result = first + second;

    if (result % 2 == 0)
      sum += result;

    first = second;
    second = result;
  }

  cout << "The summary is:" + to_string(sum);
  return 0;
}
