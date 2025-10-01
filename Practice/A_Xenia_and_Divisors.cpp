/*
--- ---
time: 14:29:23+06:00
date: Sun 06, Apr 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/342/A (TLE)

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <algorithm>
#include <csetjmp>
#include <iostream>
#include <vector>

using namespace std;

static const string endW = "\n";

bool compare(vector<int> &a, vector<int> &b) {
  int totalA = a[0] + a[1] + a[2];
  int totalB = b[0] + b[1] + b[2];
  return totalA < totalB;
}

void solution() {
  long long int n;
  cin >> n;

  vector<int> arr;
  for (long long int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 5 || x == 7) {
      cout << -1;
      return;
    }
    arr.push_back(x);
  }
  sort(arr.begin(), arr.end());

  vector<bool> used(n);
  for (long long int i = 0; i < n; i++)
    used[i] = false;

  vector<vector<int>> subArrays;
  while (subArrays.size() < n / 3) {
    long long int start;
    for (long long int i = 0; i < n; i++)
      if ((!used[i])) {
        start = i;
        used[i] = true;
        break;
      }

    vector<int> sub;
    int first, second, third;
    first = arr[start];

    // Second!
    for (long long int i = start + 1; i < n; i++) {
      if ((!used[i]) && (arr[i] % first == 0) && arr[i] > first) {
        second = arr[i];
        used[i] = true;
        start = i;
        break;
      }
      if (i == n - 2) {
        cout << -1;
        return;
      }
    }

    // Third!
    for (int i = start + 1; i < n; i++) {
      if ((!used[i]) && (arr[i] % second == 0) && arr[i] > second) {
        third = arr[i];
        used[i] = true;
        break;
      }
      if (i == n - 1) {
        cout << -1;
        return;
      }
    }

    // for (auto item : used) {
    //   cout << item << ' ';
    // }
    // cout << endW;

    sub.push_back(first);
    sub.push_back(second);
    sub.push_back(third);
    subArrays.push_back(sub);

    // cout << first << " " << second << " " << third << endW;
  }

  sort(subArrays.begin(), subArrays.end(), compare);

  for (auto item : subArrays) {
    for (auto s : item)
      cout << s << ' ';
    cout << endW;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}