#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
        int cnt = 1;
        visited[u] = true;
        for (int& v : adj[u]) {
            if (!visited[v]) {
                cnt += dfs(v, adj, visited);
            }
        }
        return cnt;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adj(n);
       for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
       } 
       
       long long totalEdges = (long long) n * (n - 1) / 2;
       vector<bool> visited(n, false);
       for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int V = dfs(i, adj, visited);
                totalEdges -= (long long) V * (V - 1) / 2;
            }
       } 
       return totalEdges;
    }
};