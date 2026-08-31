#include <iostream>
#include <vector>
#include <fstream>
#include "../common/split.h"
using namespace std;

/*
A lenti 20×20-as rácsban négy szám be van jelölve pirossal, egy átlós vonal mentén.

E számok szorzata 26 × 63 × 78 × 14 = 1788696.

Mekkora a legnagyobb szorzata négy szomszédos számnak ugyanabban az irányban (fel, le, balra, jobbra vagy átlósan) a 20×20-as rácsban?
*/

const int SIZE = 20;
const int COUNT = 4;

int getIndex(int row, int col)
{
  return row * SIZE + col;
}

int getRow(int index)
{
  return index / SIZE;
}

int getCol(int index)
{
  return index % SIZE;
}

int main()
{
  vector<int> numbers = {};
  int max = 0;

  string myText;
  ifstream MyReadFile("src/11_Task/data.txt");

  while (getline(MyReadFile, myText))
  {
    auto row = split(myText, ' ');

    for (string number : row)
    {
      numbers.push_back(stoi(number));
    }

    cout << myText << "\n";
  }

  for (int i = 0; i < numbers.size(); i++)
  {
    int row = getRow(i);
    int col = getCol(i);

    int limit = SIZE - COUNT;

    // Horisontal
    if (col <= limit)
    {
      int result = 1;
      for (int j = 0; j < COUNT; j++)
      {
        result *= numbers[getIndex(row, col + j)];
      }

      if (result > max)
        max = result;
    }

    // Vertical
    if (row <= limit)
    {
      int result = 1;
      for (int j = 0; j < COUNT; j++)
      {
        result *= numbers[getIndex(row + j, col)];
      }

      if (result > max)
        max = result;
    }

    // Diagonal down
    if (col <= limit && row <= limit)
    {
      int result = 1;
      for (int j = 0; j < COUNT; j++)
      {
        result *= numbers[getIndex(row + j, col + j)];
      }

      if (result > max)
        max = result;
    }

    // Diagonal up
    if (col <= limit && row >= COUNT - 1)
    {
      int result = 1;
      for (int j = 0; j < COUNT; j++)
      {
        result *= numbers[getIndex(row - j, col + j)];
      }

      if (result > max)
        max = result;
    }
  }

  cout << "Result: " << max << "\n";

  MyReadFile.close();

  return 0;
}