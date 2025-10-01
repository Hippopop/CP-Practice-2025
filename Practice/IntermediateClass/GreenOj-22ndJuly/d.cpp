/*
--- ---
time: 22:38:54+06:00
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

#include <cmath>
#include <iostream>
#include <utility>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li a, b, c;
  cin >> a >> b >> c;

  if (a > b)
    swap(a, b);

  if (c > a) {
    cout << (li)((pow(2, b - a) - 1) / pow(2, c - a));
  } else {
    cout << (li)(pow(2, a - c) * ((pow(2, b - a) - 1)));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}