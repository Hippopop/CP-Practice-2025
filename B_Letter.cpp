/*
--- ---
time: 12:49:16+06:00
date: Sun 06, Apr 2025
author: Mostafijul Islam
problem: link

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

static const string endW = "\n";
void solution() {
  string heading;
  string letter;
  getline(cin, heading);
  getline(cin, letter);

  map<char, int> hMap;
  map<char, int> lMap;

  for (int i = 0; i < heading.size(); i++)
    if (heading[i] != ' ') {
      char key = heading[i];
      hMap[key]++;
    }

  for (int i = 0; i < letter.size(); i++)
    if (letter[i] != ' ') {
      char key = letter[i];
      if (lMap.count(key)) {
        lMap[key]++;
      } else {
        lMap[key] = 1;
      }
    }

  for (pair<char, int> each : lMap) {
    if (hMap[each.first] < each.second) {
      cout << "NO";
      return;
    }
  }

  cout << "YES";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}