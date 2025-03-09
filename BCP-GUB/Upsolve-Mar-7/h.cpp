/*
--- ---
time: 19:16:49+06:00
date: Fri 07, Mar 2025
author: Mostafijul Islam
problem: https://oj.gubcpa.com/contests/29/problems/28/H

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
  long long int a, b;
  cin >> a >> b;
  if (a > b) {
    cout << "A is larger";
  } else if (b > a) {
    cout << "B is larger";
  } else {
    cout << "Both are equal";
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