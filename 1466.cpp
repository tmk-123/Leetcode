#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& x : connections) {
            graph[x[0]].push_back({x[1], 1}); // đúng hướng(cần đổi nếu duyệt ngược)
            graph[x[1]].push_back({x[0], 0});
        }        

        int changes = 0;
        vector<bool> visited(n, false);
        dfs(0, graph, visited, changes);
        return changes;
    }

    void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int& changes) {
        visited[node] = true;
        for (auto& [neighbor, direction] : graph[node]) {
            if (!visited[neighbor]) {
                changes += direction;
                dfs(neighbor, graph, visited, changes);
            }
        }
    }
};