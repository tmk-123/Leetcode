#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& x : prerequisites) {
            adj[x[1]].push_back(x[0]);
            inDegree[x[0]]++; // hướng từ x1 -> x0
        }

        queue<int> q;
        vector<int> topo;

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int& neighbor : adj[node]) {
                inDegree[neighbor]--; // xóa dần đỉnh
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if (topo.size() != numCourses) return {};
        return topo;
    }
};