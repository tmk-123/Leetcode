#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            adj[edges[i]].push_back(i);
        }

        long long maxScore = 0;
        int res = 0;
        for (int u = 0; u < n; u++) {
            long long score = 0;
            for (int& v : adj[u]) {
                score += v;
            }

            if (score > maxScore) {
                maxScore = score;
                res = u;
            }
        }

        return res;
    }
};