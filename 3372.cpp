#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>>& tree, int k) {
        int n = tree.size();
        vector<int> v(n, 0);
        if (k == -1) return v;

        for (int i = 0; i < n; i++) {
            queue<int> q; q.push(i);
            vector<int> distance(n, 0);
            vector<bool> visited(n, false); visited[i] = true;
            int cnt = 0;

            while (!q.empty()) {
                int node = q.front(); q.pop();
                cnt++;

                for (int& neighbor : tree[node]) {
                    if (!visited[neighbor] && distance[node] + 1 <= k) {
                        visited[neighbor] = true;
                        distance[neighbor] = distance[node] + 1;
                        q.push(neighbor);
                    }
                }
            }
            v[i] = cnt;
        }

        return v; 
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> tree1(n), tree2(m);

        for (auto& edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }
    
        for (auto& edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        vector<int> v1 = bfs(tree1, k);
        vector<int> v2 = bfs(tree2, k - 1);

        int max2 = *max_element(v2.begin(), v2.end());

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = v1[i] + max2;
        }
        return ans;
    }
};