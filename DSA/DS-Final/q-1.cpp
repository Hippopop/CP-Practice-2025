#include<bits/stdc++.h>
using namespace std;



int graph[7][7] = {
        1, 1, 1, 0, 0, 0, 0,
        1, 0, 1, 1, 0, 0, 1,
        1, 1, 0, 0, 0, 1, 1, 
        0, 0, 0, 0, 0, 1, 0,
        0, 1, 0, 1, 1, 1, 1,
        0, 0, 1, 0, 0, 0, 1,
        0, 1, 1, 1, 0, 1, 0
    };
int visited[8];


void dfs( int startNode) {
    int n = 7;
    std::vector<bool> visited(n, false);
    std::stack<int> s;

    s.push(startNode);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            std::cout << "Visited: " << node << std::endl;
            visited[node] = true;
            for (int neighbor = n - 1; neighbor >= 0; --neighbor) {
                if (graph[node][neighbor] == 1 && !visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
}

int main()
{
        dfs(0);
}