#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
Az első tíz számjegyét kell kiszámolni a következő száz darab 50 jegyű szám összegének.

Írásbeli összeadás
*/

const int NUMBER_LENGTH = 50;

int main()
{
  string myText;
  ifstream MyReadFile("src/13_Task/data.txt");

  vector<string> numbers = {};

  while (getline(MyReadFile, myText))
  {
    numbers.push_back(myText);
  }
  MyReadFile.close();

  string result = "";
  int rest = 0;

  for (int i = NUMBER_LENGTH - 1; i >= 0; i--)
  {
    int current = 0;

    for (string number : numbers)
    {
      current += stoi(number.substr(i, 1));
    }

    current += rest;

    string currentStr = to_string(current);

    if (i == 0)
    {
      result = currentStr + result;
      break;
    }

    string value = currentStr.substr(currentStr.length() - 1, 1);
    result = value + result;

    currentStr.pop_back();
    if (currentStr.length() == 0)
    {
      rest = 0;
    }
    else
    {
      rest = stoi(currentStr);
    }
  }

  cout << result << "\n";
  cout << result.substr(0, 10) << "\n";
  return 0;
}
