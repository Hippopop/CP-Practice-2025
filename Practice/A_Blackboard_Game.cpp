/*
--- ---
time: 20:44:36+06:00
date: Tue 01, Jul 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://codeforces.com/contest/2123/problem/A

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
  li n;
  cin >> n;

  vector<bool> taken(n, false);

  for (li i = 0; i < n; i++) {
    if (!taken[i]) {
      bool found = false;
      taken[i] = true;
      for (li j = 1; j < n; j++) {
        if (!taken[j] && ((i + j - 3) % 4 == 0)) {
          found = true;
          taken[j] = true;
          break;
        }
      }
      if (!found) {
        cout << "Alice";
        return;
      }
    }
  }

  cout << "Bob";
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