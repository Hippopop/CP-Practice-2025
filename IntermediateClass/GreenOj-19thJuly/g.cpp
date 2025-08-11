/*
--- ---
time: 22:58:22+06:00
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
  li x;
  cin >> x;

  for (li i = 1, j = 1; 1; j++, i = ((j * (j + 1)) / 2))
    if (i >= x) {
      cout << j;
      break;
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}