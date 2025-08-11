/*
--- ---
time: 22:44:53+06:00
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
  li a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a + b - c == d)
    cout << "YES";
  else
    cout << "NO";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}