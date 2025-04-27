/*
--- ---
time: 21:19:16+06:00
date: Tue 22, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/710384?fbclid=IwY2xjawJwcj5leHRuA2FlbQIxMAABHgWE5w1McTuEmgaTnnoUEjo5dGdjP6Tqs2VMemPyhr9UU2cKZEY6FY2LH3gA_aem_RPFpJKnW6Tcd66gGWFmptQ#problem/E

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

static const string endW = "\n";
void solution() {
  string val;
  cin >> val;

  if (val.length() < 2) {
    cout << val;
    return;
  }

  for (int i = 1; i < val.size(); i++) {
    int x = val[i - 1] - '0';
    int y = val[i] - '0';
    if (y > x) {
      val[i - 1] = y + '0';
      val[i] = x + '0';
      cout << val;
      return;
      ;
    }
  }
  cout << val;
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