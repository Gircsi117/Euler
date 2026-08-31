#include <iostream>
using namespace std;

/*
Speciális Pitagoraszi-hármas

A Pitagoraszi-hármas három természetes szám halmaza, a < b < c, amelyekre teljesül:

a² + b² = c².

Például 3² + 4² = 9 + 16 = 25 = 5².

Pontosan egy olyan Pitagoraszi-hármas létezik, amelyre a + b + c = 1000.
Határozd meg az abc szorzatot.

a = m² - n²
b = 2mn
c = m² + n²

a + b + c = 1000

(m² - n²) + 2mn + (m² + n²) = 1000
m² - n² + 2mn + m² + n² = 1000
2mn + 2m²

2m * (n + m) = 1000
m * (m + n) = 500
*/

int main()
{
  int m = 1;
  int n = 1;
  int result = 0;

  while(true)
  {
    result = m * (m + n);
    cout << "------------------------\n";
    cout << "m = " << m << "\n";
    cout << "n = " << n << "\n";
    cout << "m * (m + n) = " << result << "\n";

    if(result == 500)
    {
      int a = (m * m) - (n * n);
      int b = 2 * m * n;
      int c = (m * m) + (n * n);

      if(a + b + c == 1000 && a > 0 && b > 0 && c > 0){
        cout << a << " + " << b << " + " << c << " = 1000\n";
        cout << "Result: " << a * b * c;
        break;
      }
    }

    n++;
    if(result > 500)
    {
      cout << "a\n";
      n = 1;
      m++;
    }
  }

  return 0;
}
