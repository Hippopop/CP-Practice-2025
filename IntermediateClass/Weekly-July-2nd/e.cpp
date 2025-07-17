/*
--- ---
time: 05:50:39+06:00
date: Mon 07, Jul 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem:
https://vjudge.net/contest/726645?fbclid=IwY2xjawLXZhhleHRuA2FlbQIxMABicmlkETFaZ01IeFVLRlBpUVlZU1VGAR6d6Uz_lAXdMjXVUzS9HmyVgArl97YENvHHLNOHPqHQqfcdl7qeC-NoYt9phA_aem_S7S7sdEEh09vemD-4ZrccQ#problem/E

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li n;
  string s;
  cin >> n >> s;

  li ans = 0;
  for (char i : s) {
    if (i == '1') {
      ans += (n - 1);
    } else {
      ans++;
    }
  }

  cout << ans;
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