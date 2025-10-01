/*
--- ---
time: 09:28:33+06:00
date: Sun 20, Apr 2025
author: Mostafijul Islam
problem: https://codeforces.com/contest/236/problem/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>
#include <vector>

using namespace std;

static const string endW = "\n";
void solution() {
  string s;
  cin >> s;

  int count = 0;
  vector<int> store(26, 0);
  for (auto x : s) {
    int idx = 'z' - x;
    if (store[idx] == 0)
      count++;
    store[idx]++;
  }

  if (count & 1) {
    cout << "IGNORE HIM!";
  } else {
    cout << "CHAT WITH HER!";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}