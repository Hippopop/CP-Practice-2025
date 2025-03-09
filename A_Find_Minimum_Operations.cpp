/*
--- ---
time: 09:23:42+06:00
date: Sun 09, Mar 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/2020/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

static const string endW = "\n";
void solution() {
  long long int x, y;
  cin >> x >> y;
  if (y == 1 || x < y) {
    cout << x;
    return;
  }

  long long int step = 0;
  vector<long long int> dp;

  while (x) {
    if (dp.empty()) {
      long long int prev = 1;
      for (int i = 0; i < x; i++) {
        long long int val = pow(y, i);
        dp.push_back(val);

        if (val < x) {
          prev = val;
        } else if (val == x) {
          step++;
          x -= val;
          //   cout << "Finished Once : " << dp.size() << "!" << endW;
          break;
        } else {
          x -= prev;
          prev = 1;
          step++;
          //   cout << "Finished Once : " << dp.size() << "!" << endW;
          break;
        }
      }
    } else {
      int prevIndex = dp.size() - 1;

      while (x) {

        if (x < y) {
          step += x;
          x = 0;
          break;
        }
        // cout << "Entered Phase 2 : " << x << " Index : " << prevIndex << "!"
        //      << endW;
        for (int i = prevIndex; i >= 0; i--) {
          long long int val = dp[i];
          if (dp[i] <= x) {
            x -= dp[i];
            step++;
            prevIndex = i;
            break;
          }
        }
      }
    }
  }

  cout << step;
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