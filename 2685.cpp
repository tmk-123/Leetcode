#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[u] = true;
        component.push_back(u);
        for (int& v : adj[u]) {
            if (!visited[v]) dfs(v, adj, visited, component);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                // đồ thị liên thông đầy đủ khi có k đỉnh và k(k - 1)/2 cạnh
                int nodes = component.size();
                int edgeCount = 0;
                for (int& node : component) {
                    edgeCount += adj[node].size();
                }
                edgeCount /= 2;

                if (edgeCount == (nodes - 1) * nodes / 2) completeComponents++; 
            }
        }

        return completeComponents;
    }
};