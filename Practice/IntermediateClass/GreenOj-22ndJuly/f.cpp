/*
--- ---
time: 22:04:37+06:00
date: Tue 22, Jul 2025
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

#include <cmath>
#include <iostream>

#define li long long int
using namespace std;

bool isPrime(int value) {
  for (li i = 2; i * i <= value; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return value >= 2;
}

static const char endW = '\n';
void solution() {
  li n;
  cin >> n;

  for (li i = 0; i < n; i++) {
    li val;
    cin >> val;

    bool found = false;
    for (li i = val; i >= sqrt(val); i--) {
      if (isPrime(i)) {
        found = !found;
        cout << i << " ";
        break;
      }
    }
    if (!found)
      cout << 0 << " ";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}