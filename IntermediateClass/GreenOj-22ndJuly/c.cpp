/*
--- ---
time: 22:59:06+06:00
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

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li a;
  cin >> a;
  li max = 0;
  li ind = -1;
  for (li i = 0; i < a; i++) {
    li val;
    cin >> val;
    if (val >= max) {
      ind = i;
      max = val;
    }
  }

  cout << ind;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}