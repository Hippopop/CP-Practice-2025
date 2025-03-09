/*
--- ---
time: 19:21:12+06:00
date: Fri 07, Mar 2025
author: Mostafijul Islam
problem: https://oj.gubcpa.com/contests/29/problems/32/K

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
  long long int a, b, c;
  cin >> a >> b >> c;
  
  if (a > b) {
    if (a > c)
      cout << a;
    else
      cout << c;
  } else {
    if (b > c)
      cout << b;
    else
      cout << c;
  }
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