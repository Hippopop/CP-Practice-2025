/*
--- ---
time: 23:27:47+06:00
date: Sat 09, Aug 2025
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

static const char endW = '\n';
void solution() {
  li n;
  cin >> n;

  li x;
  if (n & 1) {
    x = n + 1;
  } else {
    x = n;
  }

  bool even = true;
  for (li i = 2; i <= x;) {
      even = !even;
    if (even) {
      i -= 1;
    } else {
      i += 3;
    }

    if (i <= n) {
      cout << i << " ";
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}