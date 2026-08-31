#pragma once

#include <cmath>

inline bool isPrime(long long num)
{
  if (num == 1 || num == 2)
    return true;

  for (long long i = 2; i <= ceil(sqrt(num)); i++)
  {
    if (num % i == 0)
      return false;
  }

  return true;
}
