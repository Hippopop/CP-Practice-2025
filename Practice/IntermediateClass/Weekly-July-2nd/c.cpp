/*
--- ---
time: 21:29:28+06:00
date: Sun 06, Jul 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://vjudge.net/contest/726645?fbclid=IwY2xjawLXZhhleHRuA2FlbQIxMABicmlkETFaZ01IeFVLRlBpUVlZU1VGAR6d6Uz_lAXdMjXVUzS9HmyVgArl97YENvHHLNOHPqHQqfcdl7qeC-NoYt9phA_aem_S7S7sdEEh09vemD-4ZrccQ#problem/C

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>
#include <utility>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li n, s;
  cin >> n >> s;

  vector<pair<pair<li, li>, li>> record;
  for (li i = 0; i < s; i++) {
    li l, r;
    cin >> l >> r;
    record.emplace_back(make_pair(l, r), 0);
  }

  li q;
  cin >> q;
  bool found = false;
  for (li i = 1; i <= q; i++) {
    li x;
    cin >> x;

    if (!found) {
      for (auto &item : record) {
        pair<li, li> range = item.first;
        li &count = item.second;

        if (x >= range.first && x <= range.second) {
          count++;
          if ((count * 2) > (range.second - range.first + 1)) {
            cout << i;
            found = true;
            break;
          }
        }
      }
    }
  }

  if (!found)
    cout << -1;
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