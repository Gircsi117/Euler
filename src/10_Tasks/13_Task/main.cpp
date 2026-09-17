#include <iostream>
#include <fstream>
#include <vector>
#include "../../common/math.h"
using namespace std;

/*
Az első tíz számjegyét kell kiszámolni a következő száz darab 50 jegyű szám összegének.

Írásbeli összeadás
*/

const int NUMBER_LENGTH = 50;

int main()
{
  string myText;
  ifstream MyReadFile("src/10_Tasks/13_Task/data.txt");

  vector<string> numbers = {};

  while (getline(MyReadFile, myText))
  {
    numbers.push_back(myText);
  }
  MyReadFile.close();

  string result = sum(numbers);

  cout << result << "\n";
  cout << result.substr(0, 10) << "\n";
  return 0;
}
