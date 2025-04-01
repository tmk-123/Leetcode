#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[u] = true;
        for (int& v : adj[u]) {
            if (!visited[v]) {
                dfs(v, adj, visited);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto& x : invocations) {
            adj[x[0]].push_back(x[1]);
        }

        vector<bool> visited(n, false);
        dfs(k, adj, visited);

        for (auto& x : invocations) {
            if (!visited[x[0]] && visited[x[1]]) {
                vector<int> res(n);
                for (int i = 0; i < n; i++) res[i] = i;
                return res;
            }
        }
        
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};