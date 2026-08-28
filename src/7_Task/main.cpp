#include <iostream>
#include <cmath>
using namespace std;

/*
Az első hat prímszámot felsorolva: 2, 3, 5, 7, 11 és 13, láthatjuk, hogy a 6. prím a 13.

Mi a 10001. prímszám?
*/

bool is_prim(long long num)
{
  if (num == 1 || num == 2)
    return true;

  for (long long i = 2; i <= ceil(num / 2); i++)
  {
    if (num % i == 0)
      return false;
  }

  return true;
}

int main()
{
  int goal = 10001;
  int count = 0;

  int num = 1;

  while (count != goal)
  {
    num++;

    if (is_prim(num))
    {
      count++;
    }
  }

  cout << "The prim number is: " + to_string(num);
  return 0;
}
