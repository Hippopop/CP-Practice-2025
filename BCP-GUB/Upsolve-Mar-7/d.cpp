/*
--- ---
time: 16:16:14+06:00
date: Fri 07, Mar 2025
author: Mostafijul Islam
problem: https://oj.gubcpa.com/contests/29/problems/22/D

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
  string data;
  cin >> data;

  int array[10] = {};
  for (int i = 0; i < data.size(); i++)
    array[data[i] - '0']++;

  bool pure = true;
  for (int i = 0; i < 10; i++) {
    if (array[i] != 0 && !(array[i] & 1)) {
      pure = false;
      break;
    }
  }
  cout << (pure ? "Joss" : "HaHaHa");
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