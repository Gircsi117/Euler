#include <iostream>
#include <vector>
#include "../common/math.h"
using namespace std;

/*
Egy permutáció az objektumok egy rendezett elrendezése. Például a 3124 az 1, 2, 3 és 4 számjegyek egy lehetséges permutációja.
Ha az összes permutációt numerikusan vagy ábécésorrendben soroljuk fel, azt lexikografikus sorrendnek nevezzük. A 0, 1 és 2 lexikografikus permutációi:

012 021 102 120 201 210

Mi a milliomodik lexikografikus permutációja a 0, 1, 2, 3, 4, 5, 6, 7, 8 és 9 számjegyeknek?

1234, 1243, 1324, 1342, 1423, 1432,
2134, 2143, 2314, 2341, 2413, 2431,
3124, 3142, 3214, 3241, 3412, 3421,
4123, 4132, 4213, 4231, 4312, 4321

*/

int main()
{
  const int LIMIT = 1000000-1;
  vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int value = LIMIT;
  string result = "";

  while (numbers.size() > 0)
  {
    const int n = numbers.size();
    int f = factorial(n - 1);

    const int index = (value / f);
    result += to_string(numbers[index]);
    numbers.erase(numbers.begin() + index);

    value -= f * index;
  }

  cout << "Result: " << result;
  return 0;
}