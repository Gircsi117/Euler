#include <iostream>
#include <cmath>
using namespace std;

/*
Az első tíz természetes szám négyzeteinek összege:

1² + 2² + ... + 10² = 385.

Az első tíz természetes szám összegének négyzete:

(1 + 2 + ... + 10)² = 55² = 3025.

Így az első tíz természetes szám négyzeteinek összege és az összeg négyzete közötti különbség 3025 − 385 = 2640.

Határozd meg az első száz természetes szám négyzeteinek összege és az összeg négyzete közötti különbséget.
*/

int main()
{
  int count = 100;

  int sum = ((count * (count + 1)) / 2) * ((count * (count + 1)) / 2);
  cout << "Sum: " + to_string(sum) + "\n";

  int pow = (count * (count + 1) * (2 * count + 1)) / 6;
  cout << "Pow: " + to_string(pow) + "\n";

  cout << "Dif:" + to_string(sum - pow);
  return 0;
}
