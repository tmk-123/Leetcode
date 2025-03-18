#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        if (visited[node] == 1) return true;
        if (visited[node] == 2) return false;

        visited[node] = 1;

        for (int& neighbor : adj[node]) {
            if (visited[neighbor] == 1) return true;
            if (visited[neighbor] == 0) {
                if (dfs(neighbor, adj, visited)) return true;
            }
        }

        visited[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& x : prerequisites) {
            adj[x[1]].push_back(x[0]);
        }    

        vector<int> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited)) return false;
            }
        }
        return true;
    }
};