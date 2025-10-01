/*
--- ---
time: 16:09:55+06:00
date: Sun 09, Feb 2025
author: Mostafijul Islam
problem: https://codeforces.com/problemset/problem/1138/A

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v) {
  cout << "Vector: ";
  for (auto x : v)
    cout << x << " ";
  cout << endl;
}

void solution() {
  int t;
  cin >> t;

  int current = -1;
  int count = 0;
  vector<int> ll;
  while (t--) {
    int v;
    cin >> v;
    if (v == current) {
      count++;
      if (t == 0)
        ll.push_back(count);
    } else {
      if (count != 0)
        ll.push_back(count);
      count = 1;
      current = v;
      if (t == 0)
        ll.push_back(count);
    }
  }

  int single = 0;
  for (int i = 1; i < ll.size(); i++) {
    int l = ll[i - 1];
    int r = ll[i];
    int smallest = (l >= r) ? r : l;
    if (smallest > single) {
      single = smallest;
    }
  }
  cout << single * 2;
}

int main() {
  solution();
  cout << endl;
  return 0;
}