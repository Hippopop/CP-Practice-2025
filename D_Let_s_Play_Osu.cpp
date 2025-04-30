/*
--- ---
time: 15:57:35+06:00
date: Sun 20, Apr 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://codeforces.com/contest/236/problem/D

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>

#define li long long int
using namespace std;

static const string endW = "\n";
void solution() {
  long long int n;
  cin >> n;

  double prob[n];
  for (long long int i = 0; i < n; i++)
    cin >> prob[i];

  long long int total = pow(2, n);
  vector<vector<int>> array(total, vector<int>(n, -1));

  for (long long int j = 0; j < total; j++) {
    for (long long int i = 0; i < n; i++) {
      double p = prob[i];
      if (j < (total * p)) {
        array[j][i] = 0;
      } else {
        array[j][i] = 1;
      }
    }
  }

  for (long long int j = 0; j < total; j++) {
    for (long long int i = 0; i < n; i++)
      cout << array[j][i];
    cout << endW;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}