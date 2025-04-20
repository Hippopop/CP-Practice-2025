/*
--- ---
time: 16:30:49+06:00
date: Sun 13, Apr 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/253/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>

using namespace std;

static const string endW = "\n";
void solution() {
  int b, g;
  cin >> b >> g;

  bool isBoys = g > b;
  while (b != g) {
    if (b > g) {
      cout << "B";
      b--;
    } else {
      cout << "G";
      g--;
    }
  }

  int total = b + g;
  for (int i = 0; i < total; i++) {
    if (isBoys) {
      cout << "B";
      b--;
      isBoys = !isBoys;
    } else {
      cout << "G";
      g--;
      isBoys = !isBoys;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  solution();
  cout << endW;

  return 0;
}