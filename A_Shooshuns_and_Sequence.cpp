/*
--- ---
time: 14:06:55+06:00
date: Sun 06, Apr 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/222/A

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
  long long int n, k;
  cin >> n >> k;

  long long int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  long long int finalVal = arr[k - 1];
  for (int i = k - 1; i < n; i++) {
    if (finalVal != arr[i]) {
      cout << -1;
      return;
    }
  }

  long long int val = 1;
  for (long long int i = k - 2; i >= 0; i--) {
    if (finalVal == arr[i]) {
      val++;
    } else {
      break;
    }
  }

  cout << k - val;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}