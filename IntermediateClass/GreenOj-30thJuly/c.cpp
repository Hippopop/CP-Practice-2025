/*
--- ---
time: 22:46:17+06:00
date: Wed 30, Jul 2025
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
  unsigned long long x, y;
  cin >> x >> y;
  unsigned long long val = floor(x / 2);
  cout << val * ((y * (y - 1)) / 2);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}