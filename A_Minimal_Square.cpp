/*
--- ---
time: 16:16:11+06:00
date: Sun 16, Feb 2025
author: Mostafijul Islam
problem: https://codeforces.com/contest/1360/problem/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>

using namespace std;

void solution() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << (a + a) * (a + a);
    return;
  }
  int da = a + a;
  int db = b + b;

  if (a > b && db >= a) {
    cout << db * db;
    return;
  } else if (a > b && db <= a) {
    cout << a * a;
    return;
  } else if (a < b && da >= b) {
    cout << da * da;
    return;
  } else if (a < b && da <= b) {
    cout << b * b;
    return;
  }
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solution();
    cout << endl;
  }
  return 0;
}