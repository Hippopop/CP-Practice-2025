/*
--- ---
time: 22:31:06+06:00
date: Tue 22, Jul 2025
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

#include <iostream>
#include <set>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li n;
  cin >> n;

  for (li i = 0; i < n; i++) {
    li x, y;
    cin >> x >> y;

    set<double> distinct;
    distinct.insert((float)x + y);
    distinct.insert((float)x - y);
    distinct.insert((float)y - x);
    distinct.insert((float)y * x);
    if (x != 0)
      distinct.insert((float)y / x);
    if (y != 0)
      distinct.insert((float)x / y);

    cout << distinct.size() << endW;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  return 0;
}