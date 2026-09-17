#include <iostream>
using namespace std;

/*
Ha felsoroljuk a 10-nél kisebb természetes számokat, amelyek 3 vagy 5 többszörösei, akkor 3, 5, 6 és 9 adódik. Ezek összege 23.

Határozd meg a 3 vagy 5 többszöröseinek összegét 1000 alatt.
*/

int main()
{
  int sum = 0;

  for (int i = 0; i < 1000; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
      sum += i;
  }

  cout << "The summary is: " + to_string(sum);
  return 0;
}
