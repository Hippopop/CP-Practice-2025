/*
--- ---
time: 19:21:12+06:00
date: Fri 07, Mar 2025
author: Mostafijul Islam
problem: https://oj.gubcpa.com/contests/29/problems/30/I

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
  string t;
  cin >> t;

  int count = 0;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == '2') {
      count++;
    }
  }
  cout << count;
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