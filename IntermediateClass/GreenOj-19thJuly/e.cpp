/*
--- ---
time: 22:33:32+06:00
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

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li n, t;
  cin >> n >> t;

  li count = 0;
  for (li i = 0; i < n; i++) {
    li x;
    cin >> x;
    if (x % t == 0)
      count++;
  }

  cout << count;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}