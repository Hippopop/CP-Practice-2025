/*
--- ---
time: 10:55:32+06:00
date: Sun 09, Mar 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/2042/B

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
#include <vector>


using namespace std;

static const string endW = "\n";

bool compare(pair<int, int> &a, pair<int, int> b) {
  return a.second > b.second;
}

void solution() {
  int n;
  cin >> n;

  map<int, int> collection;
  while (n--) {
    int val;
    cin >> val;
    if (collection.count(val) == 0) {
      collection[val] = 1;
    } else {
      collection[val]++;
    }
  }

  vector<pair<int, int> > state;
  copy(collection.begin(), collection.end(), back_inserter(state));

  sort(state.begin(), state.end(), compare);

  int scoredA = 0;
  int lastPicked = -1;

  int i = 1;
  for (int j = state.size() - 1; j >= 0; j--) {
    pair<int, int> val = state[j];

    if (i & 1) {
      if (val.second == 1) {
        scoredA += 2;
        i++;
      } else {
        scoredA++;
        i += val.second;
      }
    } else {
      if (val.second == 1) {
        i++;
      } else {
        scoredA++;
        i += val.second;
      }
    }
  }

  cout << scoredA;
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