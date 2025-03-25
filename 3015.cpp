#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n + 1);
        for (int i = 1; i < n; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        adj[x].push_back(y);
        adj[y].push_back(x);

        vector<int> res(n, 0);

        for (int start = 1; start <= n; start++) {
            queue<int> q;
            q.push(start);
            vector<int> dist(n + 1, -1);
            dist[start] = 0;

            while (!q.empty()) {
                int u = q.front(); q.pop();

                for (int& v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                        res[dist[v] - 1]++;
                    }
                }
            }
        }

        return res;
    }
};