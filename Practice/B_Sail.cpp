/*
--- ---
time: 17:22:45+06:00
date: Sun 16, Feb 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/298/B

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>

using namespace std;

void solution() {
  long long int t, x, y, tx, ty;
  cin >> t >> x >> y >> tx >> ty;

  string d;
  cin >> d;

  for (int i = 0; i <= t; i++) {
    if (tx == x && ty == y) {
      cout << i;
      return;
    }

    switch (d[i]) {
    case 'E': {
      if (tx > x)
        x++;
      break;
    };
    case 'W': {
      if (tx < x)
        x--;
      break;
    };
    case 'N': {
      if (ty > y)
        y++;
      break;
    };
    case 'S': {
      if (ty < y)
        y--;
      break;
    };
    }
  }

  cout << -1;
}

int main() {
  solution();
  cout << endl;
  return 0;
}