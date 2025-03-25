#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, -1);
        vector<vector<pair<int, int>>> adj(n);
        queue<pair<int, int>> q;

        vector<bool> v1(n, false), v2(n, false); // visited1, visited2

        for (auto& edge : redEdges) adj[edge[0]].push_back({edge[1], 1});
        for (auto& edge : blueEdges) adj[edge[0]].push_back({edge[1], 2});

        res[0] = 0;
        v1[0] = v2[0] = true;
        for (auto& [next, color] : adj[0]) {
            q.push({next, color});
            if (res[next] == -1) res[next] = 1;
        }
        int dist = 1;
        
        while (!q.empty()) {
            int size = q.size();
            dist++;
            for (int i = 0; i < size; i++) {
                auto [u, color] = q.front();
                q.pop();
                if (color == 1) v1[u] = true;
                else v2[u] = true;

                for (auto& [v, nextColor] : adj[u]) {
                    if (color == 1 && (v2[v] || nextColor == 1)) continue;
                    if (color == 2 && (v1[v] || nextColor == 2)) continue;

                    q.push({v, nextColor});           
                    if (res[v] == -1) res[v] = dist;
                }
            }
        }

        return res;
    }
};