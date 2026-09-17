#include <iostream>
#include <vector>
using namespace std;

/*
Ha az 1-től 5-ig terjedő számokat szavakkal kiírjuk: one, two, three, four, five, akkor összesen 3 + 3 + 5 + 4 + 4 = 19 betűt használunk.

Ha az 1-től 1000-ig (ezer) terjedő összes számot szavakkal kiírnánk, hány betűt használnánk?

MEGJEGYZÉS: A szóközöket és kötőjeleket ne számold. Például a 342 (three hundred and forty-two) 23 betűt tartalmaz, a 115 (one hundred and fifteen) pedig 20 betűt. Az "and" szó használata a számok kiírásakor a brit nyelvhasználatnak felel meg.
*/

vector<string> ones = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve"};
vector<string> teens = {"", "", "", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string toWords(int num)
{
  if (num == 1000)
    return "one thousand";

  string result = "";

  if (num / 100 > 0)
  {
    result += ones[num / 100] + " hundred";
    num %= 100;

    if (num > 0)
      result += " and ";
  }

  if (num <= 12)
  {
    result += ones[num];
  }
  else if (num < 20)
  {
    result += teens[num - 10];
  }
  else
  {
    result += tens[num / 10] + " ";
    result += ones[num % 10];
  }

  return result;
}

int length(string word)
{
  int result = 0;

  for (int i = 0; i < word.length(); i++)
  {
    if (word.substr(i, 1) != " ")
    {
      result++;
    }
  }

  return result;
}

int main()
{
  int result = 0;

  for (int i = 1; i <= 1000; i++)
  {
    string word = toWords(i);
    result += length(word);

    //cout << i << ". => " << word << "\n";
  }

  cout << "Result: " << result << "\n";
  return 0;
}
