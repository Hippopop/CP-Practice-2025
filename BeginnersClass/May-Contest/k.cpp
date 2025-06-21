/*
--- ---
time: 23:55:23+06:00
date: Mon 19, May 2025
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

#include <bits/stdc++.h>
#include <iostream>

#define li long long int
using namespace std;

static const string endW = "\n";
void solution() {
  li arr[5];
  for (li i = 0; i < 5; i++)
    if (i != 2)
      cin >> arr[i];

  arr[2] = arr[3] - arr[1];

  li t = 0;
  for (li i = 2; i < 5; i++)
    if (arr[i - 1] + arr[i - 2] == arr[i])
      t++;

  cout << t;
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