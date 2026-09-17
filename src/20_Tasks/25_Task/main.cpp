#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include "../../common/math.h"
#include "../../common/primes.h"
#include "../../common/sort.h"
#include "../../common/string.h"

using namespace std;

/*
A Fibonacci-sorozatot a következő rekurzív reláció definiálja:

Fₙ = Fₙ₋₁ + Fₙ₋₂, ahol F₁ = 1 és F₂ = 1.

Ennek megfelelően az első 12 tag a következő:

F₁ = 1
F₂ = 1
F₃ = 2
F₄ = 3
F₅ = 5
F₆ = 8
F₇ = 13
F₈ = 21
F₉ = 34
F₁₀ = 55
F₁₁ = 89
F₁₂ = 144

A 12. tag, F₁₂, az első, amely három számjegyből áll.

Mi az indexe a Fibonacci-sorozat első olyan tagjának, amely 1000 számjegyből áll?
*/

int main()
{
  string a = "1";
  string b = "1";

  long long index = 2;

  while (b.length() < 1000)
  {
    string summary = sum(vector<string>{a, b});

    //cout << a << " + " << b << " = " << summary << "\n";

    a = b;
    b = summary;
    index++;
  }

  cout << "Result: " << b << "\n";
  cout << "Index: " << index << "\n";
  return 0;
}
