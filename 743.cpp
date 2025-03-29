#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& v : times) {
            adj[v[0]].push_back({v[1], v[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        
        while (!pq.empty()) {
            int curDistance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (curDistance > distance[node]) continue;

            for (auto& [neighbor, w] : adj[node]) {
                if (w + curDistance < distance[neighbor]) {
                    distance[neighbor] =  w + curDistance;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) return -1;
            ans = max(ans, distance[i]);
        }
        return ans;
    }
};