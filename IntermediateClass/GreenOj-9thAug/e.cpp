/*
--- ---
time: 22:56:29+06:00
date: Sat 09, Aug 2025
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

#include <algorithm>
#include <iostream>
#include <vector>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li n;
  cin >> n;
  vector<li> arr(n);
  for (auto &i : arr)
    cin >> i;

  sort(arr.begin(), arr.end());
  string ans = "";
  for (li i = n - 1; i > 0; i--) {
    if (!(arr[i] % arr[i - 1] == 0)) {
      cout << -1;
      return;
    } else {
      ans.insert(0, to_string(arr[i]) + " ");
    }
  }

  ans.insert(0, to_string(arr[0]) + " ");
  cout << ans;
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