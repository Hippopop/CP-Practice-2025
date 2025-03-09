/*
--- ---
time: 15:20:59+06:00
date: Fri 07, Mar 2025
author: Mostafijul Islam
problem: https://oj.gubcpa.com/contests/29/problems/19/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

static const string endW = "\n";
void solution() {
  double i;
  cin >> i;

  double single = i / 2;
  cout << fixed << setprecision(2) << single * single;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  std::cin >> t;
  while (t--) {
    solution();
    cout << endl;
  }
  return 0;
}