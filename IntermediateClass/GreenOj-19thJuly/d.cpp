/*
--- ---
time: 22:37:05+06:00
date: Sat 19, Jul 2025
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

#include <functional>
#include <iostream>
#include <vector>

#define li long long int
using namespace std;

static const char endW = '\n';
void solution() {
  li n, m;
  cin >> n >> m;

  vector<li> food(n);
  vector<li> plate(m);

  for (li i = 0; i < n; i++) {
    li x;
    cin >> x;
    food.push_back(x);
  }

  for (li i = 0; i < n; i++) {
    li x;
    cin >> x;
    plate.push_back(x);
  }

  sort(food.begin(), food.end(), greater<li>());
  sort(plate.begin(), plate.end(), greater<li>());

  li count = 0;
  if (n < m) {
    for (li i = 0, j = 0; i < n && j < m; i++) {
      
    }
  } else {
    for (li i = 0; i < m; i++) {
      li x;
      cin >> x;
      food.push_back(x);
    }

    cout << count;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}