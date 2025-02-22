#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> bob_time;
    int maxProfit = INT_MIN;

    bool dfs_bob(int node, int parent, int time) {
        bob_time[node] = time; 
        if (node == 0) return true; 
    
        for (int &next : adj[node]) {
            if (next == parent) continue; 
            if (dfs_bob(next, node, time + 1)) return true; 
        }

        // Nếu không tìm thấy đường về 0, đặt lại bob_time[node] để bỏ qua nhánh sai
        bob_time[node] = INT_MAX;
        return false;
    }
    
    

    void dfs_alice(int node, int parent, int time, int profit, vector<int>& amount) {
        if (time < bob_time[node] || bob_time[node] == INT_MAX) profit += amount[node];
        else if (time == bob_time[node]) profit += amount[node] / 2;

        bool isLeaf = true;
        for (int &next : adj[node]) {
            if (next == parent) continue;
            isLeaf = false;
            dfs_alice(next, node, time + 1, profit, amount);
        }
        if (isLeaf) maxProfit = max(maxProfit, profit);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.assign(n, vector<int>());
        bob_time.assign(n, INT_MAX);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs_bob(bob, -1, 0);
        dfs_alice(0, -1, 0, 0, amount);
        return maxProfit;
    }
};

int main() {
    vector<vector<int>> v = {
        {0, 1}, {1, 2}, {1, 3}, {3, 4}
    };
    vector<int> a = {-2,4,2,-4,6};
    Solution sol;
    cout << sol.mostProfitablePath(v, 3, a);
}   