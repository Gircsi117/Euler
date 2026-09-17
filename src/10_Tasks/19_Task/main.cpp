#include <iostream>
#include <vector>
using namespace std;

/*
A következő információk állnak rendelkezésedre, de ha szeretnél, utánanézhetsz magad is:

- 1900 január 1. hétfő volt.
- Harminc napja van szeptembernek, áprilisnak, júniusnak és novembernek. A többinek harmincegy, kivéve a februárt, aminek huszonnyolc, szökőévben pedig huszonkilenc napja van.
- Szökőév az, amely osztható 4-gyel, de ha századév, akkor csak akkor, ha osztható 400-zal is.

Hány vasárnap esett a hónap első napjára a huszadik században (1901. január 1. és 2000. december 31. között)?
*/

vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year)
{
  bool four = year % 4 == 0;
  bool hundred = year % 100 == 0;
  bool fourHundred = year % 400 == 0;

  return (four && !hundred) || fourHundred;
}

int main()
{
  int year = 1900;
  int month = 0;
  int day = 0;

  int result = 0;

  while (year < 2001)
  {
    if (day == 6 && year > 1900)
      result++;

    int dayCount = days[month];
    if (month == 1 && isLeapYear(year))
      dayCount++;

    day = (day + (dayCount % 7)) % 7;

    if (++month == 12)
    {
      month = 0;
      year++;
    }
  }

  cout << "Result: " << result;
  return 0;
}
