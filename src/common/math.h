#pragma once
using namespace std;

inline long long factorial(long long num)
{
  long long result = 1;
  for (long long i = 1; i <= num; i++)
  {
    result *= i;
  }
  return result;
}