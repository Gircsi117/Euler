#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include "../common/split.h"
using namespace std;

/*
A data.txt fájl egy 46 KB méretű szövegfájl, amely több mint ötezer keresztnevet tartalmaz.
Először rendezd ábécésorrendbe. Ezután számítsd ki minden név ábécé-értékét, és szorozd meg ezt az értéket a névnek a listában elfoglalt ábécé szerinti helyével,
hogy megkapd a név pontszámát.

Például: ábécésorrendbe rendezve a COLIN, aminek értéke 3 + 15 + 12 + 9 + 14 = 53, a lista 938. neve. Így a COLIN pontszáma 938 × 53 = 49714.

Mennyi az összes névpontszám összege a fájlban?
*/

map<char, int> abc;

int getNameValue(string name)
{
  int result = 0;

  for (int i = 0; i < name.length(); i++)
  {
    char cstr = name[i];
    result += abc[cstr];
  }

  return result;
}

int main()
{
  for (char c = 'A'; c <= 'Z'; ++c)
  {
    abc[c] = c - 'A' + 1;
  }

  long long result = 0;

  string myText;
  ifstream MyReadFile("src/22_Task/data.txt");

  vector<string> names;

  //*
  while (getline(MyReadFile, myText))
  {
    names = split(myText, ',');

    for (auto &&name : names)
    {
      name = name.substr(1, name.length() - 2);
    }

    sort(names.begin(), names.end());
  }
  MyReadFile.close();

  //*
  for (int i = 0; i < names.size(); i++)
  {
    result += getNameValue(names[i]) * (i + 1);
  }

  cout << "Result: " << result;
  return 0;
}
