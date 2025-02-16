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

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solution() {
  int d;
  cin >> d;
  vector<int> items;
  for (int i = 0; i < d; i++) {
    int k;
    cin >> k;
    items.push_back(k);
  }
  sort(items.begin(), items.end());

  int l = 1;
  for (int i : items)
    if (i >= l) {
      l++;
    }

  cout << l - 1;
}

int main() {
  solution();
  cout << endl;
  return 0;
}