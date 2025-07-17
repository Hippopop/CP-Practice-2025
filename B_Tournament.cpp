/*
--- ---
time: 21:40:26+06:00
date: Tue 01, Jul 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://codeforces.com/contest/2123/problem/B

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li x, y, z;
  cin >> x >> y >> z;

  vector<li> players;
  li target = -1;
  for (li i = 0; i < x; i++) {
    li v;
    cin >> v;
    if (i + 1 == y)
      target = v;

    if (v > target) {
      players.push_back(v);
    }
  }

  li greaterCount = 0;
  for (auto i : players) {
    // cout << i;
    if (i > target)
      greaterCount++;
  }

  //   cout << endW << greaterCount << " " << target << endW;
  if (greaterCount - 2  == z - 1) {
    cout << "YES";
  } else {
    cout << "NO";
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