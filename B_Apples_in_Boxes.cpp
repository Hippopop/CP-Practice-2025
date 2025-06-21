/*
--- ---
time: 22:19:09+06:00
date: Mon 05, May 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://codeforces.com/contest/2107/problem/B

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

static const string endW = "\n";
void solution() {
  li n, k;
  cin >> n >> k;

  vector<li> options(n);
  li total = 0;
  li high = 0, low = 0;
  for (li i = 0; i < n; i++) {
    cin >> options[i];
    total += options[i];
    if (options[i] > high || i == 0)
      high = options[i];
    if (options[i] < low || i == 0)
      low = options[i];
  }

  if ((high - low) > k + 1) {
    cout << "Jerry";
    return;
  }

  if (total & 1)
    cout << "Tom";
  else
    cout << "Jerry";
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