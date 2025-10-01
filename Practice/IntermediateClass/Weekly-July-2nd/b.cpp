/*
--- ---
time: 20:59:40+06:00
date: Sun 06, Jul 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem:
https://vjudge.net/contest/726645?fbclid=IwY2xjawLXZhhleHRuA2FlbQIxMABicmlkETFaZ01IeFVLRlBpUVlZU1VGAR6d6Uz_lAXdMjXVUzS9HmyVgArl97YENvHHLNOHPqHQqfcdl7qeC-NoYt9phA_aem_S7S7sdEEh09vemD-4ZrccQ#problem/B

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
  li n, s;
  cin >> n >> s;

  li array[n];
  for (li i = 0; i < n; i++) {
    cin >> array[i];
  }

  li left = array[0];
  li right = array[n - 1];

  if (s < left) {
    cout << right - s;
    return;
  }
  if (s > right) {
    cout << s - left;
    return;
  }

  li ld = s - left;
  li rd = right - s;

  if (ld > rd) {
    cout << rd * 2 - 1 + ld + 1;
  } else {
    cout << ld * 2 - 1 + rd + 1;
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