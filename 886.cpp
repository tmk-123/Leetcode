#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool bfs(vector<vector<int>>& adj, int n, int node, vector<int>& colors) {
        queue<int> q;
        q.push(node);
        colors[node] = 1;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int& v : adj[u]) {
                if (colors[v] = colors[u]) return false;
                if (colors[v] == -1) {
                    colors[v] = 1 - colors[u];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<int> colors(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (colors[i] == -1) {
                if (!bfs(adj, n, i, colors)) return false;
            }
        }
        return true;
    }
};