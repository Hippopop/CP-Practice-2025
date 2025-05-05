/*
--- ---
time: 12:56:22+06:00
date: Mon 28, Apr 2025
author: Mostafijul Islam
problem: link

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

static const string endW = "\n";
void solution() {
  string line;
  int t = 0;

  while (getline(cin, line)) {
    int n, m;
    stringstream(line) >> n >> m;
    if (n == 0 && m == 0) {
      t++;
      break;
    } else {
      t++;
      if (t != 1)
        cout << endW;
    }

    vector<vector<long long int>> mat(n, vector<long long int>(m, 0));

    cout << "Field #" << t << ":" << endW;
    for (int i = 0; i < n; i++) {
      string r;
      getline(cin, r);

      for (int j = 0; j < m && r.size() == m; j++) {
        if (r[j] == '*') {
          mat[i][j] = -(10);
          int pairs[8][2] = {
              {i - 1, j - 1}, {i - 1, j},     {i - 1, j + 1}, {i, j - 1},
              {i, j + 1},     {i + 1, j - 1}, {i + 1, j},     {i + 1, j + 1},
          };

          for (auto v : pairs) {
            int y = v[0], x = v[1];
            if (y >= 0 && x >= 0 && y < n && x < m) {
              mat[y][x]++;
            }
          }
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (mat[i][j] < 0)
          cout << '*';
        else
          cout << mat[i][j];
      cout << endW;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  return 0;
}