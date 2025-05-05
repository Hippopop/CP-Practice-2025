/*
--- ---
time: 06:38:49+06:00
date: Mon 28, Apr 2025
author: Mostafijul Islam
problem:
https://vjudge.net/contest/710169?fbclid=IwZXh0bgNhZW0CMTEAYnJpZBExUk1uTEtuaHIzRlI2SGM2cQEeF09x6T8EkZ34xl_IHtW7W9gQbdfNOdkmpawX2eaUsxjwe70-u35lSFV8eAc_aem_XHXFKeokKAFhS3CvDtxGKQ#problem/B

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

static const string endW = "\n";
void solution() {
  string line;
  while (getline(cin, line) && !line.empty()) {
    int count = 0;
    stringstream stream(line);

    while (getline(stream, line, ' ')) {
      for (auto i : line)
        if (isalpha(i)) {
          count++;
          break;
        }
    }

    cout << count << endW;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();

  return 0;
}