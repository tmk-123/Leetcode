#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPaths;
    
    void dfs(int u, vector<vector<int>>& adj, vector<int> path, int n, vector<bool>& visited) {
        path.push_back(u);
        visited[u] = true;

        if (u == n - 1) {
            allPaths.push_back(path);
            return;
        }

        for (int& v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, path, n, visited);
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);

        dfs(0, graph, {}, n, visited);
        return allPaths;    
    }
};