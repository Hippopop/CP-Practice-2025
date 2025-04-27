/*
--- ---
time: 17:51:30+06:00
date: Tue 22, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/710384?fbclid=IwY2xjawJwcj5leHRuA2FlbQIxMAABHgWE5w1McTuEmgaTnnoUEjo5dGdjP6Tqs2VMemPyhr9UU2cKZEY6FY2LH3gA_aem_RPFpJKnW6Tcd66gGWFmptQ#problem/B

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
  int arr[3];
  for (int i = 0; i < 3; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + 3);
  if (arr[2] != arr[0] && arr[1] != arr[0]) {
    cout << arr[1] << " " << arr[0] << " " << arr[2];
  } else {
    cout << -1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}