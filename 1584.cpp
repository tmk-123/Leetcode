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

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges;
        parent.assign(n, -1);
        Rank.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        int totalCost = 0, edgesUsed = 0;

        for (auto& [cost, u, v] : edges) {
            if (unite(u, v)) {
                totalCost += cost;
                if (++edgesUsed == n - 1) break;
            }
        }
        
        return totalCost;
    }
};