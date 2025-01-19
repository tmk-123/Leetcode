#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(int current, int destination, unordered_map<int, vector<int>> graph, unordered_set<int>& visited) {
        if (current == destination) return true;
        visited.insert(current);
        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(neighbor, destination, graph, visited)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        return dfs(source, destination, graph, visited);
    }
};

int main() {
    vector<vector<int>> v = {
        {0, 1},
        {1, 2}, 
        {2, 0},
    };

    Solution sol;
    cout << sol.validPath(3, v, 0, 2);
}