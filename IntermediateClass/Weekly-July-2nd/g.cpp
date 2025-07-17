/*
--- ---
time: 22:36:20+06:00
date: Wed 09, Jul 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem:
https://vjudge.net/contest/726645?fbclid=IwY2xjawLXZhhleHRuA2FlbQIxMABicmlkETFaZ01IeFVLRlBpUVlZU1VGAR6d6Uz_lAXdMjXVUzS9HmyVgArl97YENvHHLNOHPqHQqfcdl7qeC-NoYt9phA_aem_S7S7sdEEh09vemD-4ZrccQ#problem/G

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li n;
  cin >> n;

  li arr[n];
  vector<vector<li>> history(n - 2, vector<li>(3));

  for (li i = 0; i < n; i++) {
    cin >> arr[i];
    if (i >= 2) {
      history[i - 2] = {arr[i - 2], arr[i - 1], arr[i]};
    }
  }

  for (li i = 0; i < n - 2; i++) {
    cout << history[i][0] << " " << history[i][1] << " " << history[i][2]
         << endW;
  }

  li count = 0;
  for (li i = 0; i < n - 2; i++) {
    vector<li> one = history[i];

    for (li j = i + 1; j < n - 2; j++) {
      vector<li> two = history[j];

      if ((one[0] == two[0] && one[1] == two[1] && one[2] != two[2]) ||
          (one[0] == two[0] && one[1] != two[0] && one[2] == two[2]) ||
          (one[0] != two[0] && one[1] == two[0] && one[2] == two[2])) {
        count++;
      }
    }
  }

  cout << count;
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