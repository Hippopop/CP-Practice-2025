/*
--- ---
time: 09:11:16+06:00
date: Sun 09, Mar 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/2065/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>

using namespace std;

static const string endW = "\n";
void solution() {
  string verb;
  cin >> verb;

  for (int i = 0; i < verb.size() - 2; i++)
    cout << verb[i];
  cout << 'i';
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