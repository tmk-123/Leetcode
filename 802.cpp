#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rGraph(n);
        vector<int> inDegree(n, 0);
        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            for (int v : graph[i]) {
                rGraph[v].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
                safeNodes.push_back(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int& v : rGraph[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                    safeNodes.push_back(v);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};