#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<bool> visited;
    void dfs(int u, int n, vector<vector<int>>& isConnected) {
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (isConnected[u][v] == 1 && !visited[v]) {
                dfs(v, n, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        visited.assign(n, false);

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, n, isConnected);
            }
        }

        return components;
    }
};