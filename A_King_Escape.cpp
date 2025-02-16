/*
--- ---
time: 11:17:05+06:00
date: Sun 16, Feb 2025
author: Mostafijul Islam
problem: http://codeforces.com/problemset/problem/1033/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>

using namespace std;

void solution() {
  int d;
  cin >> d;
  int qx, qy;
  cin >> qx >> qy;
  int kx, ky;
  cin >> kx >> ky;
  int tx, ty;
  cin >> tx >> ty;

  //   Final Calculation!!
  int kp;
  if (kx > qx) {
    if (ky > qy)
      kp = 4;
    else
      kp = 2;
  } else {
    if (ky > qy)
      kp = 3;
    else
      kp = 1;
  }

  int tp;
  if (tx > qx) {
    if (ty > qy)
      tp = 4;
    else
      tp = 2;
  } else {
    if (ty > qy)
      tp = 3;
    else
      tp = 1;
  }

  if (kp == tp)
    cout << "YES";
  else
    cout << "NO";
}

int main() {
  solution();
  cout << endl;
  return 0;
}