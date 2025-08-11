/*
--- ---
time: 22:40:59+06:00
date: Sat 09, Aug 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

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

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li a, b;
  cin >> a >> b;

  vector<li> l(a);
  for (auto &i : l) {
    cin >> i;
  }

  vector<li> c(b);
  for (auto &i : c) {
    cin >> i;
  }

  for (auto i : c) {
    li idx = lower_bound(l.begin(), l.end(), i) - l.begin();
    cout << l[idx] + 1 << endW;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  return 0;
}