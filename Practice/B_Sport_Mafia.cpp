/*
--- ---
time: 11:17:05+06:00
date: Sun 16, Feb 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/1165/B

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>

using namespace std;

void solution() {
  long long int d, e;
  cin >> d >> e;

  long long int sum = 0;
  for (long long int i = 1; i <= d; i++) {
    sum = (i * (i + 1)) / 2;
    if (sum == e && i == d) {
      cout << 0;
      return;
    }

    int eat = d - i;
    if (sum - eat == e) {
      cout << eat;
      return;
    }
  }
}

int main() {
  solution();
  cout << endl;
  return 0;
}