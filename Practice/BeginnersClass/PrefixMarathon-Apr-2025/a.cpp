/*
--- ---
time: 18:31:23+06:00
date: Fri 25, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/711895?fbclid=IwZXh0bgNhZW0CMTEAYnJpZBExUk1uTEtuaHIzRlI2SGM2cQEe1x3YlZBKiN-4p25dcVByOMwPSojinoK-r_yCaFo5FgmgirIFwf4PyQN1Xio_aem_FGmRf5kTLXf9C-fMQ4YjUw#problem

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
  li n;
  cin >> n;

  li longest = 1;
  li left = 0, right = 0;
  vector<li> prev;

  for (li i = 0; i < n; i++) {
    li val;
    cin >> val;
    li length = (right - left) + 1;

    bool found = false;
    li foundIndex = 0;
    for (li j = left; j < i; j++)
      if (prev[j] == val) {
        found = !found;
        foundIndex = j;
      }

    if (found) {
      length--;

      if (length > longest) {
        longest = length;
      }

      left = foundIndex + 1;
    }

    prev.push_back(val);
    right++;

    if (i == n - 1 && length > longest) {
      longest = length;
    }
  }

  cout << longest;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}