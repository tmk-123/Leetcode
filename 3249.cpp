#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> adj;
    int goodNodes = 0;

    int dfs(int node, int parent) {
        int size = 1;
        unordered_map<int, int> childSizes;

        for (int& neighbor : adj[node]) {
            if (neighbor == parent) continue;
            int childSize = dfs(neighbor, node);
            size += childSize;
            childSizes[childSize]++;
        }

        if (childSizes.size() <= 1) goodNodes++;
        return size;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);
        return goodNodes;
    }
};