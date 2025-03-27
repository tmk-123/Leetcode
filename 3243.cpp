#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        vector<int> dp(n);
        for (int i = 0; i < n; i++) dp[i] = i;

        vector<int> res;
        for (auto& q : queries) {
            adj[q[1]].push_back(q[0]);
            for (int i = q[1]; i < n; i++) {
                dp[i] = min(dp[i], dp[i - 1] + 1);
                for (int& neighbor : adj[i]) {
                    dp[i] = min(dp[i], dp[neighbor] + 1);
                }
            }
            res.push_back(dp[n - 1]);
        }

        return res;
    }
};