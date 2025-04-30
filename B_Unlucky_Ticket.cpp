/*
--- ---
time: 13:28:35+06:00
date: Sun 20, Apr 2025
author: Mostafijul Islam
problem: link

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

static const string endW = "\n";
void solution() {
  int _;
  cin >> _;
  vector<int> firstHalf(_);
  vector<int> secondHalf(_);

  string s;
  cin >> s;

  for (int i = 0; i < _; i++) {
    int left = '0' - s[i];
    int right = '0' - s[i + _];
    firstHalf.push_back(left);
    secondHalf.push_back(right);
  }

  sort(firstHalf.begin(), firstHalf.end());
  sort(secondHalf.begin(), secondHalf.end());

  for (int i = 0; i < _; i++) {
    if (firstHalf[i] > secondHalf[i]) {
      if (i == (_ - 1)) {
        cout << "YES";
        return;
      }
      continue;
    }
    break;
  }

  for (int i = 0; i < _; i++) {
    if (firstHalf[i] < secondHalf[i]) {
      if (i == (_ - 1)) {
        cout << "YES";
        return;
      }
      continue;
    }
    break;
  }

  cout << "NO";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int _;

  solution();
  cout << endW;

  return 0;
}