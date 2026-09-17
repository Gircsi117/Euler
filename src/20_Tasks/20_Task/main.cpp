#include <iostream>
#include "../../common/math.h"
using namespace std;

/*
n! jelentése: n × (n − 1) × ⋯ × 3 × 2 × 1.

Például: 10! = 10 × 9 × ⋯ × 3 × 2 × 1 = 3628800, és a 10! szám számjegyeinek összege 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Határozd meg a 100! szám számjegyeinek összegét.
*/

int main()
{
  string number = "1";

  for (int i = 2; i <= 100; i++)
  {
    number = multiplication(number, i);
  }

  cout << "Number: " << number << "\n";
  cout << "Result: " << sum(number) << "\n";

  return 0;
}
