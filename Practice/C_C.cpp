/*
--- ---
time: 21:00:37+06:00
date: Tue 22, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/710384?fbclid=IwY2xjawJwcj5leHRuA2FlbQIxMAABHgWE5w1McTuEmgaTnnoUEjo5dGdjP6Tqs2VMemPyhr9UU2cKZEY6FY2LH3gA_aem_RPFpJKnW6Tcd66gGWFmptQ#problem/C

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

static const string endW = "\n";
void solution() {
  int n;
  cin >> n;

  long long int total = 0;
  for (int i = 0; i < n; i++) {
    long long int val;
    cin >> val;

    long long int output = val - total;
    total += output;
    cout << output << " ";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}