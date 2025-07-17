/*
--- ---
time: 22:32:00+06:00
date: Wed 16, Jul 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://oj.gubcpa.com/contests/54/problems/71/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <cstdlib>
#include <iostream>
#include <vector>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li s;
  cin >> s;

  if (s == 1) {
    cout << 0;
    return;
  }
  
  vector<li> arr(s, 0);
  for (li i = 0; i < s; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  cout << abs(arr[0] - arr[1]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}