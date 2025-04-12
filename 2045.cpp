#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }      

        vector<vector<int>> dist(n + 1, vector<int>(2, INT_MAX));
        queue<pair<int, int>> q;
        dist[0][0] = 0;
        q.push({1, 0});

        while (!q.empty()) {
            auto [u, curTime] = q.front();
            q.pop();

            for (int& v : adj[u]) {
                int wait = 0;
                if ((curTime / change) % 2 == 1) wait = change - (curTime % change);

                int newTime = time + curTime + wait;

                if (dist[v][0] > newTime) {
                    dist[v][1] = dist[v][0];
                    dist[v][0] = newTime;
                    q.push({v, newTime});
                }
                else if (dist[v][1] > newTime && dist[v][0] < newTime) {
                    dist[v][1] = newTime;
                    q.push({v, newTime});
                }
            }
        }

        return dist[n][1];
    }
};