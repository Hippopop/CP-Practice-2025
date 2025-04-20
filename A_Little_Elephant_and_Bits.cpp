/*
--- ---
time: 11:53:07+06:00
date: Sun 13, Apr 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/258/A

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
  string bin;
  cin >> bin;

  int idx = bin.size() - 1;
  for (int i = 0; i < bin.size(); i++)
    if (bin[i] == '0') {
      idx = i;
      break;
    }

  for (int i = 0; i < bin.size(); i++) {
    if (i != idx) {
      cout << bin[i];
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}