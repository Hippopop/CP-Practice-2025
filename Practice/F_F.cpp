/*
--- ---
time: 21:42:34+06:00
date: Tue 22, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/710384?fbclid=IwY2xjawJwcj5leHRuA2FlbQIxMAABHgWE5w1McTuEmgaTnnoUEjo5dGdjP6Tqs2VMemPyhr9UU2cKZEY6FY2LH3gA_aem_RPFpJKnW6Tcd66gGWFmptQ#problem/F

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
  long long int n, q;
  cin >> n >> q;

  long long int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  while (q--) {
    long long int x, y;
    cin >> x >> y;
    long long int sum = 0;
    for (int i = x - 1; i < y; i++)
      sum += arr[i];

    cout << sum << endW;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  return 0;
}