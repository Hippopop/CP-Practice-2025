/*
--- ---
time: 12:15:08+06:00
date: Sun 13, Apr 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/350/A

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
  int s, f;
  cin >> s >> f;

  int sList[s];
  int fList[f];
  for (int i = 0; i < s; i++)
    cin >> sList[i];
  for (int i = 0; i < f; i++)
    cin >> fList[i];

  sort(sList, sList + s);
  sort(fList, fList + f);

  int min = sList[0];
  int max = sList[s - 1];

  if (min * 2 >= max && (min * 2 < fList[0])) {
    cout << min * 2;
    return;
  }

  if (min == max && (max * 2 < fList[0])) {
    cout << max * 2;
    return;
  }

  if (min * 2 <= max && max < fList[0]) {
    cout << max;
    return;
  }

  cout << -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}