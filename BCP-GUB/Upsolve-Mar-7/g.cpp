/*
--- ---
time: 18:59:23+06:00
date: Fri 07, Mar 2025
author: Mostafijul Islam
problem: https://oj.gubcpa.com/contests/29/problems/25/G

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

static const string endW = "\n";
void solution() {
  int x;
  unsigned long long int i, d, t;
  cin >> x >> i >> d;
  t = i;
  for (int i = 0; i < x; i++) {
    unsigned long long int p;
    cin >> p;
    if (t >= p) {
      cout << i;
      return;
    }
    t += d;
  }
  cout << -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}