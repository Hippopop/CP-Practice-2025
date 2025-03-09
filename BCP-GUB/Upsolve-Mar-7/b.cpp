/*
--- ---
time: 15:57:37+06:00
date: Fri 07, Mar 2025
author: Mostafijul Islam
problem: https://oj.gubcpa.com/contests/29/problems/20/B

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
  string text, target;
  cin >> text >> target;
  int count = 0;
  for (int i = 0; i <= text.size() - target.size(); i++) {
    if (text[i] == target[0]) {
      for (int j = 1; j < target.size(); j++) {
        if (text[i + j] == target[j]) {
          if (j + 1 == target.size()) {
            cout << "Love Found";
            return;
          }
        } else {
          break;
        }
      }
    }
  }
  cout << "Love Missing";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}