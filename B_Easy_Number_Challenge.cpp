/*
--- ---
time: 10:52:33+06:00
date: Tue 15, Apr 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/236/B

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>
#include <map>

using namespace std;

static const string endW = "\n";

int divisors(int n) {
  int t = 2;
  for (int i = 2; i < n / 2 + 1; i++)
    if (n % i == 0)
      t++;
  return t;
}

void solution() {
  int a, b, c;
  cin >> a >> b >> c;
  map<int, int> storage = {};
  storage[1] = 1;
  storage[2] = 2;

  long long int sum = 0;
  for (int i = 1; i <= c; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= a; k++) {
        int d = i * j * k;
        if (storage.count(d) > 0) {
          sum += storage[d];
          continue;
        }
        storage[d] = divisors(d);
        sum += storage[d];
      }
  cout << sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;
  
  return 0;
}