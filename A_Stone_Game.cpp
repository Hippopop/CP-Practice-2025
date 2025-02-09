/*
--- ---
time: 11:41:11+06:00
date: Sun 09, Feb 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/1538/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>

using namespace std;

void solution() {
  int l;
  cin >> l;
  int min = -1, max = -1;
  int iMin = 0, iMax = 0;

  for (int i = 1; i <= l; i++) {
    int j;
    cin >> j;
    if (j < min || min == -1) {
      min = j;
      iMin = i;
    }
    if (j > max || min == -1) {
      max = j;
      iMax = i;
    }
  }

  
if(iMax > iMin) {

}
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}