/*
--- ---
time: 23:52:13+06:00
date: Tue 08, Jul 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem:
https://vjudge.net/contest/726645?fbclid=IwY2xjawLXZhhleHRuA2FlbQIxMABicmlkETFaZ01IeFVLRlBpUVlZU1VGAR6d6Uz_lAXdMjXVUzS9HmyVgArl97YENvHHLNOHPqHQqfcdl7qeC-NoYt9phA_aem_S7S7sdEEh09vemD-4ZrccQ#problem/F

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
  li x;
  cin >> x;

  if (x == 1) {
    cout << "YES";
    return;
  }

  if (x & 1) {
    cout << "YES";
    return;
  } else {
    cout << "NO";
  }
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