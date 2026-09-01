#pragma once

#include <vector>
#include <cmath>

using namespace std;

vector<long long> primes = {2};

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

inline vector<long long> primeFactorization(long long number)
{
  vector<long long> dividers = {};

  // Egység vizsgálat
  if (number == 1)
    dividers.push_back(1);

  // Prím vizsgálat
  if (isPrime(number))
  {
    dividers.push_back(number);
    number = 1;
  }

  while (number != 1)
  {
    bool isDivided = false;

    // Meglévő prímek ellenőrzése
    for (long long prime : primes)
    {
      if (number % prime == 0)
      {
        dividers.push_back(prime);
        number /= prime;
        isDivided = true;
        break;
      }
    }

    // Lépünk ha már osztottunk
    if (isDivided)
      continue;

    // Ha a szám prím nem vizsgálunk más eseteket
    if (isPrime(number))
    {
      dividers.push_back(number);
      number = 1;
      break;
    }

    // Új prím meghatározása
    const long long lastPrime = primes[primes.size() - 1];
    for (long long i = lastPrime + 1; i <= number; i++)
    {
      if (isPrime(i))
      {
        primes.push_back(i);

        if (number % i == 0)
        {
          dividers.push_back(i);
          number /= i;
          break;
        }
      }
    }
  }

  return dividers;
}
