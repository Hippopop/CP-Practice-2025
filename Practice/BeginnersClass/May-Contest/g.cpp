/*
--- ---
time: 23:39:18+06:00
date: Mon 19, May 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: link

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>

#define li long long int
using namespace std;

static const string endW = "\n";
void solution() {
  li a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a == b && b == c && c == d)
    cout << "Yes";
  else
    cout << "No";
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