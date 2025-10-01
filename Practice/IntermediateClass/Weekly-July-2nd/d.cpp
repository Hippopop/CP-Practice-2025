/*
--- ---
time: 05:37:27+06:00
date: Mon 07, Jul 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem:
https://vjudge.net/contest/726645?fbclid=IwY2xjawLXZhhleHRuA2FlbQIxMABicmlkETFaZ01IeFVLRlBpUVlZU1VGAR6d6Uz_lAXdMjXVUzS9HmyVgArl97YENvHHLNOHPqHQqfcdl7qeC-NoYt9phA_aem_S7S7sdEEh09vemD-4ZrccQ#problem/D

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <string>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  string s;
  cin >> s;

  li n = stoi(s);
  li root = sqrt(n);
  if (root * root == n) {
    if (root != 0)
      cout << root - 1 << " " << 1;
    else
      cout << 0 << " " << 0;
  } else {
    cout << -1;
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