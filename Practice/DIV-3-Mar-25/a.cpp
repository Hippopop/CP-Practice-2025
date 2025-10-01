/*
--- ---
time: 20:37:18+06:00
date: Tue 25, Mar 2025
author: Mostafijul Islam
problem: https://codeforces.com/contest/2091/problem/0

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

static const string endW = "\n";
void solution() {
  long long int n;
  cin >> n;
  map<int, int> m;
  m[0] = 3;
  m[1] = 1;
  m[2] = 2;
  m[3] = 1;
  m[5] = 1;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 1; i <= n; i++) {
    int val = arr[i - 1];

    if (m.count(val) > 0) {
      if (m[val] == 1)
        m.erase(val);
      else
        m[val]--;
    }

    // cout << "Val :" << val << " | " << endW;
    // for (auto i : m) {
    //   cout << i.first << " " << i.second << endl;
    // }
    // cout << " Size : " << m.size() << endW;
    if (m.size() == 0) {
      cout << i;
      return;
    }
  }
  cout << 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  std::cin >> t;
  while (t--) {
    solution();
    cout << endW;
    // cout << " --------  ------" << endW;
  }
  return 0;
}