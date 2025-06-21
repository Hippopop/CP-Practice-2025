/*
--- ---
time: 02:11:00+06:00
date: Thu 22, May 2025
author: Mostafijul Islam
email: mostafijul929@gmail.com
github: https://github.com/Hippopop

problem: https://onlinejudge.org/external/104/p10462.pdf

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

int find(int u, vector<int> &parent) {
  return parent[u] == u ? u : parent[u] = find(parent[u], parent);
}

bool unite(int u, int v, vector<int> &parent) {
  int pu = find(u, parent), pv = find(v, parent);
  if (pu == pv)
    return false;
  parent[pu] = pv;
  return true;
}

int kruskal(int n, vector<tuple<int, int, int>> &edges,
            vector<int> *mstEdgeIdx = nullptr, int skip = -1) {
  vector<int> parent(n + 1);
  iota(parent.begin(), parent.end(), 0);

  int cost = 0, used = 0;
  for (int i = 0; i < edges.size(); ++i) {
    if (i == skip)
      continue;

    auto [w, u, v] = edges[i];
    if (unite(u, v, parent)) {
      cost += w;
      ++used;
      if (mstEdgeIdx)
        mstEdgeIdx->push_back(i);
    }
  }

  return (used == n - 1) ? cost : -1;
}

void solution() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges(m);
    for (auto &e : edges) {
      int u, v, w;
      cin >> u >> v >> w;
      e = {w, u, v};
    }

    sort(edges.begin(), edges.end());

    vector<int> mstEdges;
    int mstCost = kruskal(n, edges, &mstEdges);

    if (mstCost == -1) {
      cout << "No way\n";
      continue;
    }

    int secondBest = INT_MAX;
    for (int i : mstEdges) {
      int cost = kruskal(n, edges, nullptr, i);
      if (cost != -1 && cost > mstCost)
        secondBest = min(secondBest, cost);
    }

    if (secondBest == INT_MAX)
      cout << "No second way\n";
    else
      cout << secondBest << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  solution();

  return 0;
}