/*
--- ---
time: 18:05:02+06:00
date: Sun 06, Apr 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/327/B

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>
#include <vector>

using namespace std;

static const string endW = "\n";
const int LIMIT = 2000000;
vector<int> sieve(int n) {
  vector<bool> isPrime(LIMIT + 1, true);
  isPrime[0] = isPrime[1] = false;
  vector<int> primes;

  for (int i = 2; i <= LIMIT && primes.size() < n; ++i) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j = i * 2; j <= LIMIT; j += i) {
        isPrime[j] = false;
      }
    }
  }

  return primes;
}

void solution() {
  long long int n;
  cin >> n;
  vector<int> p = sieve(n);
  for (long long int i = 0; i < n; i++) {
    cout << p[i] << ' ';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}
