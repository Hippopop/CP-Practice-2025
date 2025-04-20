/*
--- ---
time: 11:16:44+06:00
date: Sun 13, Apr 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/242/B

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>
#include <utility>

using namespace std;

static const string endW = "\n";
void solution() {
  int n;
  cin >> n;

  long long int max = -1, min = -1, pos = -1;
  pair<long long int, long long int> expand = {-1, -1};
  for (int i = 1; i <= n; i++) {
    long long int a, b;
    cin >> a >> b;

    if (a < min || min == -1)
      min = a;
    if (b > max || max == -1)
      max = b;

    if (expand.first == -1 || (expand.first >= a && expand.second <= b)) {
      expand = {a, b};
      pos = i;
    //   cout << a << " || " << b << " || " << n << endW;
    }
  }

  if (min == expand.first && max == expand.second) {
    cout << pos;
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