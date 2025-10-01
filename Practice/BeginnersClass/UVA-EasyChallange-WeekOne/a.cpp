/*
--- ---
time: 06:28:02+06:00
date: Mon 28, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/710169?fbclid=IwZXh0bgNhZW0CMTEAYnJpZBExUk1uTEtuaHIzRlI2SGM2cQEeF09x6T8EkZ34xl_IHtW7W9gQbdfNOdkmpawX2eaUsxjwe70-u35lSFV8eAc_aem_XHXFKeokKAFhS3CvDtxGKQ#problem/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>
#include <string>

#define li long long int
using namespace std;

static const string endW = "\n";
void solution() {
  li x;
  cin >> x;

  li res = ((((x * 567) / 9 + 7492) * 235) / 47 - 498);
  string val = to_string(res);
  cout << val[val.size() - 2];
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