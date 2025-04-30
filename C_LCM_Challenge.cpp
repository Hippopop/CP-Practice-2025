/*
--- ---
time: 10:53:49+06:00
date: Sun 20, Apr 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://codeforces.com/contest/236/problem/C

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <algorithm>
#include <iostream>

using namespace std;

static const string endW = "\n";

int gcd(long long int a, long long int b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}

long long lcm(long long int a, long long int b) {
  return 1LL * a / gcd(a, b) * b;
}

void solution() {
  long long int n;
  cin >> n;

  if (n == 1) {
    cout << 1;
    return;
  }
  if (n == 2) {
    cout << 2;
    return;
  }
  if (n == 3) {
    cout << 6;
    return;
  }

  if (n & 1) {
    cout << lcm(lcm(n, n - 1), n - 2);
  } else {
    long long int result = lcm(lcm(n - 3, n - 1), n - 2);
    long long int limit = n - 10;
    if (limit < 1) {
      limit = 1;
    }

    for (long long int i = n; i >= limit; i--)
      for (long long int j = n - 1; j >= limit; j--)
        for (long long int k = n - 2; k >= limit; k--) {
          long long int l = lcm(lcm(i, j), k);
          if (l > result) {
            result = l;
          }
        }

    cout << result;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}