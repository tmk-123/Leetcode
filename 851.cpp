#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        for (auto& r : richer) {
            adj[r[0]].push_back(r[1]);
            inDegree[r[1]]++;
        }     

        vector<int> res(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            res[i] = i;
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int& v : adj[u]) {
                if (quiet[res[u]] < quiet[res[v]]) {
                    res[v] = res[u];
                }

                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return res;
    }
};