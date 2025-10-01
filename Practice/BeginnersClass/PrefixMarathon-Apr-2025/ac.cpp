/*
--- ---
time: 01:14:55+06:00
date: Mon 28, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/711895?fbclid=IwZXh0bgNhZW0CMTEAYnJpZBExUk1uTEtuaHIzRlI2SGM2cQEe1x3YlZBKiN-4p25dcVByOMwPSojinoK-r_yCaFo5FgmgirIFwf4PyQN1Xio_aem_FGmRf5kTLXf9C-fMQ4YjUw#problem/AC

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
  string x;
  cin >> x;

  li sum = 0;
  for (li i = 0; i < x.size(); i++)
    sum += (x[i] - '0');
  cout << sum;
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