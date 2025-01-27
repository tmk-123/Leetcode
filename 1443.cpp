#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        return dfs(0, -1, adj, hasApple);
    }

    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple) {
        int time = 0;

        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;

            int childTime = dfs(neighbor, node, adj, hasApple);
            if (hasApple[neighbor] || childTime > 0) time += childTime + 2;
        }

        return time;
    }
};

int main() {
    vector<vector<int>> edges = {
        {0, 1}, 
        {0, 2},
        {1, 4},
        {1, 5},
        {2, 3},
        {2, 6},
    };
    vector<bool> hasApple = {false,false,true,false,true,true,false};
    Solution sol;
    cout << sol.minTime(7, edges, hasApple);
}   