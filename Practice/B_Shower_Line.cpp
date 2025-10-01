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
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

static const string endW = "\n";

long long int countTotal(vector<vector<long long int>> arr, vector<int> order) {
  int t = 0;
  t += (arr[order[0]][order[1]] + arr[order[1]][order[0]]);
  t += (arr[order[2]][order[3]] + arr[order[3]][order[2]]);
  t += (arr[order[1]][order[2]] + arr[order[2]][order[1]]);
  t += (arr[order[3]][order[4]] + arr[order[4]][order[3]]);
  t += (arr[order[2]][order[3]] + arr[order[3]][order[2]]);
  t += (arr[order[3]][order[4]] + arr[order[4]][order[3]]);
  return t;
}

void solution() {
  vector<int> option;
  vector<vector<long long int>> arr(5);

  for (int i = 0; i < 5; i++) {
    option.push_back(i);
    for (int j = 0; j < 5; j++) {
      long long int x;
      cin >> x;
      arr[i].push_back(x);
    }
  }

  long long int max = LONG_MIN;
  do {
    long long int total = countTotal(arr, option);
    if (total > max) {
      max = total;
    }
  } while (next_permutation(option.begin(), option.end()));

  cout << max;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solution();
  return 0;
}