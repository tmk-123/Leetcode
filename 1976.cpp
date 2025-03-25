#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& r : roads) {
            adj[r[0]].emplace_back(r[1], r[2]);
            adj[r[1]].emplace_back(r[0], r[2]);
        }

        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        // current distance, node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        ways[0] = 1;
        dist[0] = 0;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [curDist, u] = pq.top();
            pq.pop();
            
            if (curDist > dist[u]) continue;

            for (auto& [v, time] : adj[u]) {
                if (dist[u] + time < dist[v]) {
                    dist[v] = dist[u] + time;
                    ways[v] = ways[u];
                    pq.emplace(dist[v], v);
                }
                else if (dist[u] + time == dist[v]) {
                    ways[v] = (ways[u] + ways[v]) % 1000000007;
                }
            }
        }

        return ways[n - 1];
    }
};