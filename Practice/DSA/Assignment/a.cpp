/*
--- ---
time: 20:58:13+06:00
date: Wed 21, May 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: http://uva.onlinejudge.org/external/5/544.html

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#define li long long int
using namespace std;

static const string endW = "\n";

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, li> cityToId;
int getCityId(const string &name) {
  static int nextId = 0;
  if (!cityToId.count(name))
    cityToId[name] = nextId++;
  return cityToId[name];
}

int maxWeightPath(int n, vector<tuple<string, string, li>> &roads,
                  string startCity, string endCity) {
  vector<vector<pair<int, int>>> adj(roads.size());
  int start = getCityId(startCity), end = getCityId(endCity);

  for (auto &[a, b, w] : roads) {
    int u = getCityId(a), v = getCityId(b);
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  vector<int> maximumFromSource(roads.size(), 0);
  maximumFromSource[start] = INT_MAX;

  priority_queue<pair<int, int>> pq;
  pq.emplace(maximumFromSource[start], start);

  while (!pq.empty()) {
    auto [maximumPossible, currentTopLocation] = pq.top();
    pq.pop();

    if (currentTopLocation == end)
      return maximumPossible;

    for (auto &[destination, weight] : adj[currentTopLocation]) {
      int minWeightFromTop = min(maximumPossible, weight);
      if (minWeightFromTop > maximumFromSource[destination]) {
        maximumFromSource[destination] = minWeightFromTop;
        pq.emplace(minWeightFromTop, destination);
      }
    }
  }

  return 0;
}

void solution() {
  li count = 1;
  li x, y;
  cin >> x >> y;
  while (x != 0 && y != 0) {
    vector<tuple<string, string, li>> items(y);
    for (li i = 0; i < y; i++) {
      string start, end;
      li weight;
      cin >> start >> end >> weight;
      items[i] = {start, end, weight};
    }
    string start, end;
    cin >> start >> end;

    li output = maxWeightPath(x, items, start, end);
    cout << "Scenario #" << count << endW;
    cout << output << " tons" << endW;
    cout << endW;
    //* Start Next!
    cin >> x >> y;
    count++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  return 0;
}