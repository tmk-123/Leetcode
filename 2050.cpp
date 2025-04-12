#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> dp(n, 0);
        
        for (auto& x : relations) {
            int u = x[0] - 1;
            int v = x[1] - 1;
            adj[u].emplace_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                dp[i] = time[i];
            }
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int& v : adj[u]) {
                // Thời điểm sớm nhất để bắt đầu v là khi tiền đề mất nhiều thời gian nhất hoàn thành
                dp[v] = max(dp[v], dp[u] + time[v]);
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};