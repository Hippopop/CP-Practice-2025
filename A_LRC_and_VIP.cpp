/*
--- ---
time: 21:22:55+06:00
date: Mon 05, May 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://codeforces.com/contest/2107/problem/0

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <numeric>
#include <vector>

#define li long long int
using namespace std;

static const string endW = "\n";
void solution() {
  li n;
  cin >> n;

  vector<li> items(n);
  for (li i = 0; i < n; i++)
    cin >> items[i];

  li l = 0;
  li l_gcd = items[l];
  li r_gcd;

  do {
    r_gcd = items[l + 1];
    for (li i = l + 2; i < n; i++) {
      r_gcd = std::gcd(r_gcd, items[i]);
    }

    if (l_gcd == r_gcd && l <= n - 2) {
      l++;
      li l_gcd = items[0];
      for (li i = 1; i <= l; i++) {
        l_gcd = std::gcd(l_gcd, items[i]);
      }
    }
  } while (l_gcd == r_gcd && l != n - 1);

  if (l_gcd == r_gcd)
    cout << "No";
  else {
    cout << "Yes" << endW;
    for (li i = 0; i < n; i++) {
      if (i <= l)
        cout << 1 << " ";
      else
        cout << 2 << " ";
    }
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