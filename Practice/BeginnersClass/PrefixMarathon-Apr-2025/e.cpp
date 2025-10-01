/*
--- ---
time: 05:16:19+06:00
date: Mon 28, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/711895?fbclid=IwZXh0bgNhZW0CMTEAYnJpZBExUk1uTEtuaHIzRlI2SGM2cQEe1x3YlZBKiN-4p25dcVByOMwPSojinoK-r_yCaFo5FgmgirIFwf4PyQN1Xio_aem_FGmRf5kTLXf9C-fMQ4YjUw#problem/E

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
  string seq;
  cin >> seq;

  vector<li> history(seq.size(), 0);

  li q;
  cin >> q;

  li count = 0;
  for (int i = 0; i < seq.size() - 1; i++) {
    if (seq[i] == seq[i + 1]) {
      count++;
    }
    history[i + 1] = count;
  }

  while (q--) {
    li l, r;
    cin >> l >> r;
    cout << history[r - 1] - history[l - 1] << endW;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();

  return 0;
}