/*
--- ---
time: 10:21:21+06:00
date: Sun 02, Mar 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/270/A

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
  double angle;
  cin >> angle;

  for (double i = 3, p = 60; p <= angle; p = ((i - 2) * 180) / i) {
    if (angle == p) {
      cout << "YES";
      return;
    }
    i++;
  }

  cout << "NO";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  std::cin >> t;
  while (t--) {
    solution();
    cout << endW;
  }
  return 0;
}