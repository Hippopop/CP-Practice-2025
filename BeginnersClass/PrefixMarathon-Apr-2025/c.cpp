/*
--- ---
time: 04:25:17+06:00
date: Mon 28, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/711895?fbclid=IwZXh0bgNhZW0CMTEAYnJpZBExUk1uTEtuaHIzRlI2SGM2cQEe1x3YlZBKiN-4p25dcVByOMwPSojinoK-r_yCaFo5FgmgirIFwf4PyQN1Xio_aem_FGmRf5kTLXf9C-fMQ4YjUw#problem/C


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
  li n, j;
  cin >> n >> j;

  li arr[n];
  li sum = 0, lowest = -1, rank = 0, prev = -1, prevSum = 0;
  for (li i = 0; i < j - 1; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  for (li i = j - 1; i < n; i++) {
    cin >> arr[i];

    li start = i - j + 1;
    if (prev == -1) {
      sum += arr[i];
    } else {
      sum = (prevSum - arr[prev]) + arr[i];
    }

    if (sum < lowest || lowest == -1) {
      lowest = sum;
      rank = start;
    }

    // Reset!
    prevSum = sum;
    prev = start;
    sum = 0;
  }

  cout << rank + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}