#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].emplace_back(e[1], e[2]);
            adj[e[1]].emplace_back(e[0], e[2]);
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [curTime, u] = pq.top(); pq.pop();
            
            if (curTime >= disappear[u] || curTime > dist[u]) continue;

            for (auto& [v, w] : adj[u]) {
                if (curTime + w < min(dist[v], disappear[v])) {
                    dist[v] = curTime + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] >= disappear[i] || dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};