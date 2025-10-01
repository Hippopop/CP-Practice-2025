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
#include <vector>

using namespace std;

static const string endW = "\n";

void solution() {
  int a, b, c;
  cin >> a >> b >> c;
  const int size = (a * b * c) + 1;
  vector<int> storage(size, 0);
  for (int i = 1; i < size; i++)
    for (int j = i; j < size; j += i)
      storage[j]++;

  long long int sum = 0;
  for (int i = 1; i <= c; i++)
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= a; k++) {
        int d = i * j * k;
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