/*
--- ---
time: 13:16:58+06:00
date: Sun 09, Feb 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/1843/B

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>
#include <vector>

using namespace std;

long long int getTotal(vector<int> d) {
  long long int total = 0;
  for (auto x : d)
    total += x;
  return total;
}

void print(vector<int> v) {
  cout << "Vector: ";
  for (auto x : v)
    cout << x << " ";
  cout << endl;
}

void solution() {
  int t;
  cin >> t;
  int l = -1;
  int c = 0;
  long long int total = 0;
  vector<int> digits;
  for (int i = 0; i < t; i++) {
    int x;
    cin >> x;
    if (l == -1 && x < 0) {
      l = i;
    }
    if (x < 0) {
      total = total + (x * -1);
    } else {
      total += x;
    }
    digits.push_back(x);
  }

  long long int cTotal = 0;
  cTotal = getTotal(digits);
  while (cTotal != total) {
    c++;
    int neg = 0;
    int pos = 0;
    int r = l;
    for (int i = l; i < t; i++) {
      bool last = i == t - 1;

      if (digits[i] <= 0) {
        r = i;
        neg++;
      } else {
        break;
      }
    }

    for (int i = l; i <= r; i++) {
      digits[i] = (digits[i] * (-1));
      cTotal += digits[i] * 2;
    }

    for (int i = r; i < t; i++) {
      if (digits[i] < 0) {
        l = i;
        break;
      }
    }
  }

  cout << total << " " << c;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    solution();
    cout << endl;
  }
  return 0;
}