/*
--- ---
time: 00:52:00+06:00
date: Thu 22, May 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://codeforces.com/contest/20/problem/C

*INPUT*
- ???

*QUESTION*
- ???
--- ---
*/

#include <bits/stdc++.h>
#include <iostream>

#define li long long int
using namespace std;

static const string endW = "\n";
const long long INF = 1e18;

void dijkstra(int n, vector<vector<pair<int, int>>> &graph) {
  vector<long long> dist(n + 1, INF);
  vector<int> parent(n + 1, -1);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>
      pq;

  dist[1] = 0;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d > dist[u])
      continue;

    for (auto &[v, w] : graph[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        pq.push({dist[v], v});
      }
    }
  }

  if (dist[n] == INF) {
    cout << -1 << "\n";
    return;
  }

  vector<int> path;
  for (int cur = n; cur != -1; cur = parent[cur])
    path.push_back(cur);
  reverse(path.begin(), path.end());

  for (int x : path)
    cout << x << " ";
  cout << "\n";
}

void solution() {
  li n, m;
  cin >> n >> m;

  map<pair<int, int>, int> minEdge;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u > v)
      swap(u, v);
    pair<int, int> edge = {u, v};
    if (minEdge.count(edge) == 0 || w < minEdge[edge])
      minEdge[edge] = w;
  }

  vector<vector<pair<int, int>>> graph(n + 1);
  for (auto &[edge, w] : minEdge) {
    int u = edge.first;
    int v = edge.second;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  dijkstra(n, graph);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();
  cout << endW;

  return 0;
}