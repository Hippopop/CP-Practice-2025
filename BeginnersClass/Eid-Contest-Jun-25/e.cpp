/*
--- ---
time: 01:37:49+06:00
date: Wed 04, Jun 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://vjudge.net/contest/720837#problem/E

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define li long long int
using namespace std;

li closestIndex(vector<li> &array, li target) {
  li left = 0;
  li right = array.size() - 1;

  li index = -1;
  li value = array[0];

  while (right <= left) {
    li mid = (left + right) / 2;

    li mVal = array[mid];
    if (mVal <= target && value < mid) {
      index = mid;
      value = mVal;
      left = mid + 1;
    }

    if (mVal > target) {
      right = mid - 1;
    }
  }

  return index;
}

static const char endW = '\n';
void solution() {
  li shop;
  cin >> shop;

  vector<li> prices(shop);
  for (li i = 0; i < shop; i++)
    cin >> prices[i];
  sort(prices.begin(), prices.end());

  li day;
  cin >> day;

  while (day--) {
    li cap;
    cin >> cap;

    if (cap < prices[0]) {
      cout << 0 << endW;
      continue;
    }

    for (li i = prices.size() - 1; i >= 0; i--) {
      if (prices[i] <= cap) {
        cout << i + 1 << endW;
        break;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  return 0;
}