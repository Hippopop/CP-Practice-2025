/*
--- ---
time: 22:23:32+06:00
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

#include <iostream>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  unsigned li a, b, m;
  cin >> a >> b >> m;

  if (a > m) {
    a %= m;
  }
  if (b > m) {
    b %= m;
  }

  cout << (a + b) % m;
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