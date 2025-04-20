/*
--- ---
time: 20:46:40+06:00
date: Tue 25, Mar 2025
author: Mostafijul Islam
problem: https://codeforces.com/contest/2091/problem/B

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>

using namespace std;

static const string endW = "\n";
void solution() {
  long long int n, x;
  cin >> n >> x;

  vector<int> arr;
  long long int team = 0;
  for (int i = 0; i < n; i++) {
    long long int v;
    cin >> v;
    if (v >= x) {
      team++;
    } else {
      arr.push_back(v);
    }
  }

  sort(arr.begin(), arr.end());

  while (arr.size()) {
    int added = 0;
    int lowest = arr[arr.size() - 1];
    for (int i = arr.size() - 1; i >= 0; i--) {
      int val = arr[i];
      if (val <= lowest) {
        lowest = val;
        added++;
        if (added * lowest >= x) {
          team++;
          break;
        }
      }
    }
    for (int i = 0; i < added; i++)
      arr.pop_back();
    // long long int smallest = arr[0];
    // long long int len = ceil((double)x / (double)smallest);
    // cout << "Size " << arr.size() << " || Smallest: " << smallest
    //      << " || Len: " << len << endW;
    // if (len > arr.size()) {
    //   arr.erase(arr.begin());
    //   continue;
    // }
    // for (int i = 1; i <= len; i++) {
    //   arr.erase(arr.begin());
    // }
    // team++;
  }

  cout << team;
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