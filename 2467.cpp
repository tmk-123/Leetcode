#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> bobTime;
    int maxProfit = INT_MIN;

    bool dfsBob(int u, int parent, int time) {
        bobTime[u] = time;
        if (u == 0) return true;
        
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (dfsBob(v, u, time + 1)) return true;
        }
        
        bobTime[u] = INT_MAX; // gán lại = INT_MAX nếu không thấy đường
        return false;
    }

    void dfsAlice(int u, int parent, int time, int profit, vector<int>& amount) {
        if (time < bobTime[u] || bobTime[u] == INT_MAX) profit += amount[u];
        else if (time == bobTime[u]) profit += amount[u] / 2;

        bool isLeaf = true;
        for (int v : adj[u]) {
            if (parent == v) continue;
            isLeaf = false;
            dfsAlice(v, u, time + 1, profit, amount);
        }
        if (isLeaf) maxProfit = max(maxProfit, profit);
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.assign(n, vector<int>());
        bobTime.assign(n , INT_MAX);    
        
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfsBob(bob, -1, 0);
        dfsAlice(0, -1, 0, 0, amount);
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