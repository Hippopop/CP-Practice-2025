/*
--- ---
time: 22:09:35+06:00
date: Sat 19, Jul 2025
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
#include <numeric>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li n;
  cin >> n;

  li sum = 0;
  for (li i = 0; i < n; i++) {
    li x, y;
    cin >> x >> y;

    sum += lcm(x, y);
  }

  cout << sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}