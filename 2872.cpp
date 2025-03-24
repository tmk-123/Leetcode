#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

        int components = 1;
        vector<long long> subtreeSum(values.begin(), values.end());

        while (!q.empty()) {
            int u = q.front(); q.pop();
            degree[u]--;
            if (subtreeSum[u] % k == 0) components++;    

            for (int& v : adj[u]) {
                if (degree[v] == 0) continue;
                subtreeSum[v] += subtreeSum[u];
                degree[v]--;
                if (degree[v] == 1) q.push(v);
            }
        }
        return components;
    }
};