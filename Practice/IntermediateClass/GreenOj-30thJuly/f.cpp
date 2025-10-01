/*
--- ---
time: 23:06:00+06:00
date: Wed 30, Jul 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: link

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>

#define li long long int
using namespace std;

// Found this logic on a website! 😑😑
long long numberOfDivisors(long long num) {
  long long total = 1;
  for (int i = 2; (long long)i * i <= num; i++) {
    if (num % i == 0) {
      int e = 0;
      do {
        e++;
        num /= i;
      } while (num % i == 0);
      total *= e + 1;
    }
  }
  if (num > 1) {
    total *= 2;
  }
  return total;
}

static const char endW = '\n';
void solution() {
  unsigned long long l, r;
  cin >> l >> r;

  li s = 0;
  for (li i = l; i <= r; i++) {
    li sum = numberOfDivisors(i);
    if (sum % 2 != 0)
      s++;
  }

  cout << s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}