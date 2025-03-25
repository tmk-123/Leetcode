#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
     vector<int> parent, Rank;

    int find(int u) {
        if (u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;

        if (Rank[pu] < Rank[pv]) parent[pu] = pv;
        else if (Rank[pv] < Rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            Rank[u]++;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        Rank.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
        
        for (auto& edge : edges) {
            if (!unite(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};