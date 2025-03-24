#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);

        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            inDegree[x[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<set<int>> ancestors(n);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int& v : adj[u]) {
                ancestors[v].insert(u);
                ancestors[v].insert(ancestors[u].begin(), ancestors[u].end());

                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
        }
        return res;
    }
};