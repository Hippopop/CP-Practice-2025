/*
--- ---
time: 11:10:36+06:00
date: Sun 02, Mar 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/431/B

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

static const string endW = "\n";

void sort(map<pair<long long int, long long int>, long long int> &current) {
  map<long long int, pair<long long int, long long int>> sortedMap;
  for (auto it : current) {
    sortedMap.insert(make_pair(it.second, it.first));
  }

  for (auto x : sortedMap) {
    cout << "(" << x.second.first << " " << x.second.second << ")"
         << " " << x.first << endW;
  }
}

void solution() {
  long long int arr[5][5];

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      long long int x;
      cin >> x;
      arr[i][j] = x;
    }

  map<pair<long long int, long long int>, long long int> dict;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      int total = arr[i][j] + arr[j][i];
      if (dict.count(make_pair(i, j)) == 0 && dict.count(make_pair(j, i)) == 0)
        dict.insert(make_pair(make_pair(i, j), total));
    }

  sort(dict);

  //   for (auto x : dict) {
  //     cout << "(" << x.first.first << " " << x.first.second << ")"
  //          << " " << x.second << endW;
  //   }

  /* long long int highest = 0;
  int lH = 0, rH = 0;

  int endTotal = 0;

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      if (i == j)
        continue;
      int total = arr[i][j] + arr[j][i];
      if (total > highest) {
        highest = total;
        lH = i;
        rH = j;
      }
    }

  endTotal += (highest * 2);

  cout << "After Phase 1 : lH:" << lH << " rH:" << rH << " Highest:" << highest
       << " total:" << endTotal << endW;

  long long int shighest = 0;
  int slH = 0;

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      if (i == j)
        continue;
      if (i == lH && j != rH) {
        int total = arr[i][j] + arr[j][i];
        if (total > shighest) {
          shighest = total;
          slH = j;
        }
      }
      if (i == rH && j != rH) {
        int total = arr[i][j] + arr[j][i];
        if (total > shighest) {
          shighest = total;
          slH = j;
          long long int temp = lH;
          lH = rH;
          rH = temp;
        }
      }
    }

  endTotal += (shighest * 2);
  cout << "After Phase 2 : lH:" << lH << " rH:" << rH << " slH:" << slH
       << " SHighest:" << shighest << " total:" << endTotal << endW;

  long long int s1 = 0;
  int last = 0;

  for (int j = 0; j < 5; j++) {
    if (j == lH || j == rH)
      continue;
    int total = arr[slH][j] + arr[j][slH];
    if (total > s1) {
      s1 = total;
      last = j;
    }
  }
  endTotal += s1;
  cout << "After Phase 2 : lH:" << lH << " rH:" << rH << " slH:" << slH
       << " last:" << last << " SHighest:" << shighest << " total:" << endTotal
       << endW;

  long long int s2 = 0;
  for (int j = 0; j < 5; j++) {
    if (j == lH || j == rH || j == slH)
      continue;
    int total = arr[last][j] + arr[j][last];
    if (total > s2) {
      s2 = total;
    }
  }
  endTotal += s1; */

  //   cout << endTotal << endW;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();

  return 0;
}