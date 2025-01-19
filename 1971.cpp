#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        unordered_set<int> visited;
        q.push(source);
        visited.insert(source);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (current == destination) return true;
            for (int neighbor : graph[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return false;
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