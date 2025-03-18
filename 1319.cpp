#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int u) {
        visited[u] = true;
        for (int& v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, visited, v);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<vector<int>> adj(n);
        for (auto& x : connections) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, visited, i);
                components++;
            } 
        }

        return components - 1;
    }
};