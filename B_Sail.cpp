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
  bool l = tx<x, r = tx> x, up = ty<y, down = ty> y;

  //   cout << "X: " << x << " Y: " << y << " TX: " << tx << " TY: " << ty <<
  //   endl; cout << "Left: " << l << " Right: " << r << " UP: " << up << "
  //   DOWN: " << down
  //        << endl;

  string d;
  cin >> d;

  for (int i = 1; i <= t; i++) {
    switch (d[i - 1]) {
    case 'E': {
      if (r)
        x++;
      if (tx == x && ty == y) {
        cout << i;
        return;
      }
      break;
    };
    case 'W': {
      if (l)
        x--;
      if (tx == x && ty == y) {
        cout << i;
        return;
      }
      break;
    };
    case 'N': {
      if (down)
        y++;
      if (tx == x && ty == y) {
        cout << i;
        return;
      }
      break;
    };
    case 'S': {
      if (up)
        y--;
      if (tx == x && ty == y) {
        cout << i;
        return;
      }
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