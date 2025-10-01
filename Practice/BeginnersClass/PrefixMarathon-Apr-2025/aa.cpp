/*
--- ---
time: 01:34:59+06:00
date: Mon 28, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/711895?fbclid=IwZXh0bgNhZW0CMTEAYnJpZBExUk1uTEtuaHIzRlI2SGM2cQEe1x3YlZBKiN-4p25dcVByOMwPSojinoK-r_yCaFo5FgmgirIFwf4PyQN1Xio_aem_FGmRf5kTLXf9C-fMQ4YjUw#problem/AA

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>

#define pi (2 * acos(0.0))

using namespace std;

static const string endW = "\n";
void solution(int test) {
  double x;
  cin >> x;

  cout << fixed << setprecision(2) << "Case " << test << ": "
       << (((x * 2) * (x * 2)) - (pi * (x) * (x)) + pow(10, -9));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  std::cin >> t;
  for (int i = 1; i <= t; i++) {
    solution(i);
    cout << endW;
  }
  return 0;
}