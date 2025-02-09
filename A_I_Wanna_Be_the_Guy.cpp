/*
--- ---
time: 23:58:51+06:00
date: Mon 27, Jan 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/469/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
  int totalLevel;
  set<int> levelList;
  cin >> totalLevel;

  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    int v;
    cin >> v;
    levelList.insert(v);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int v;
    cin >> v;
    levelList.insert(v);
  }

  if (levelList.size() == totalLevel) {
    cout << "I become the guy." << endl;
  } else {
    cout << "Oh, my keyboard!" << endl;
  }

  return 0;
}