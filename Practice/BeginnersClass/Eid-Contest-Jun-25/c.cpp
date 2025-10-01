/*
--- ---
time: 00:37:08+06:00
date: Tue 03, Jun 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://vjudge.net/contest/720837#problem/C

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <cmath>
#include <iostream>

#define li long long int
using namespace std;

bool isTriangular(li val) {
  li rValue = 1 + 8 * val;
  li root = sqrt(rValue);
  if (root * root != rValue) {
    return false;
  } else {
    li base = (root - 1) / 2;
    li baseOutput = (base * (base + 1)) / 2;
    return baseOutput == val;
  }
}

static const char endW = '\n';
void solution() {
  li x;
  cin >> x;

  for (li i = 1, val = 1; val < x; i++, val = (i * (i + 1)) / 2) {
    li left = x - val;
    if (isTriangular(left)) {
      cout << "Yes";
      return;
    }
  }
  cout << "No";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}