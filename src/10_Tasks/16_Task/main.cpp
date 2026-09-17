#include <iostream>
#include "../../common/math.h"
using namespace std;

/*
2¹⁵ = 32768, és a számjegyeinek összege 3 + 2 + 7 + 6 + 8 = 26.

Mennyi a 2¹⁰⁰⁰ szám számjegyeinek összege?

írásbeli szórzás.
*/

const int LIMIT = 1000;

int main()
{
  string number = "2";
  int result = 0;

  for (int i = 1; i < LIMIT; i++)
  {

    number = multiplication(number, 2);
  }

  result = sum(number);

  cout << "Number: " << number << "\n";
  cout << "Result: " << result << "\n";

  return 0;
}
