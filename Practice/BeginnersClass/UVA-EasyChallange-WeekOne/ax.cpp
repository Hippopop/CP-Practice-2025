/*
--- ---
time: 22:45:11+06:00
date: Mon 28, Apr 2025
author: Mostafijul Islam
problem: https://vjudge.net/contest/710169#problem/AX

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
  string line;
  int i = 0;
  while (getline(cin, line) && !line.empty()) {
    if (i != 0)
      cout << endW;
    else
      i++;
    
    stringstream stream(line);

    while (getline(stream, line, ' ')) {
      for (int i = line.size() - 1; i >= 0; i--) {
        cout << line[i];
      }
      cout << ' ';
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  return 0;
}