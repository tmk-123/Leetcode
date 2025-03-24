#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dfs(int root, int parent, int dist, vector<vector<pair<int, int>>>& graph, int signalSpeed) {
        int count = (dist % signalSpeed == 0) ? 1 : 0;
        for (auto& [neighbor, w] : graph[root]) {
            if (neighbor != parent) {
                count += dfs(neighbor, root, dist + w, graph, signalSpeed);
            }
        }
        return count;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(n);
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int nodeCount = 0, res = 0;

            for (auto& [neighbor, w] : graph[i]) {
                int countSubtree = dfs(neighbor, i, w, graph, signalSpeed);
                res += nodeCount * countSubtree;
                nodeCount += countSubtree;
            }
            ans[i] = res;
        }

        return ans;
    }
};