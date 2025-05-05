/*
--- ---
time: 23:55:30+06:00
date: Sun 27, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/711895?fbclid=IwZXh0bgNhZW0CMTEAYnJpZBExUk1uTEtuaHIzRlI2SGM2cQEe1x3YlZBKiN-4p25dcVByOMwPSojinoK-r_yCaFo5FgmgirIFwf4PyQN1Xio_aem_FGmRf5kTLXf9C-fMQ4YjUw#problem/AB

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
void solution(li test) {
  cout << "Case " << test << ":" << endW;
  li x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  li n;
  cin >> n;

  while (n--) {
    li tx, ty;
    cin >> tx >> ty;

    if (tx > x1 && tx < x2 && ty > y1 && ty < y2) {
      cout << "Yes" << endW;
      continue;
    }
    cout << "No" << endW;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  li t;
  std::cin >> t;
  for (li i = 1; i <= t; i++) {
    solution(i);
  }
  return 0;
}