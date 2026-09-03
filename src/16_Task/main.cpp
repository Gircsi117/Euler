#include <iostream>
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
    string current = "";
    int rest = 0;

    for (int i = number.length() - 1; i >= 0; i--)
    {
      int num = stoi(number.substr(i, 1)) * 2 + rest;

      string numStr = to_string(num);

      if (i == 0)
      {
        current = numStr + current;
        continue;
      }

      string last = numStr.substr(numStr.length() - 1, 1);

      current = last + current;

      string r = numStr.substr(0, numStr.length() - 1);
      if (r == "")
      {
        rest = 0;
      }
      else
      {
        rest = stoi(r);
      }
    }

    // cout << current << "\n";
    number = current;
  }

  for (int i = 0; i < number.length(); i++)
  {
    result += stoi(number.substr(i, 1));
  }

  cout << "Number: " << number << "\n";
  cout << "Result: " << result << "\n";

  return 0;
}
