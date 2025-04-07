#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }

        int minCycle = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;
            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int& v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                    else if (parent[u] != v) {
                        minCycle = min(minCycle, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        if (minCycle == INT_MAX) return -1;
        return minCycle;
    }
};