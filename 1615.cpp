#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<unordered_set<int>> adj(n);

        for (auto& road : roads) {
            int u = road[0], v = road[1];
            degree[u]++;
            degree[v]++;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        int maxRank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];
                if (adj[i].count(j)) rank--;
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};