#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        vector<double> prob(n, 0.0);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});    
        prob[start_node] = 1.0;  
        while (!pq.empty()) {
            auto [curProb, u] = pq.top();
            pq.pop();

            for (auto& [p, v] : adj[u]) {
                if (p * curProb > prob[v]) {
                    prob[v] = curProb * p;
                    pq.push({prob[v], v});
                }
            }
        }

        return prob[end_node];
    }
};