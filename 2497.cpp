#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<vector<int>> adj(vals.size());
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int maxStar = INT_MIN;
        for (int i = 0; i < vals.size(); i++) {
            int sum = vals[i], cnt = 0;
            vector<int> neighbors;
            for (int& neighbor : adj[i]) neighbors.push_back(vals[neighbor]);
            sort(neighbors.rbegin(), neighbors.rend());

            for (int& val : neighbors) {
                if (val <= 0 || cnt >= k) break;
                cnt++;
                sum += val;
            }
            maxStar = max(maxStar, sum);
        }

        return maxStar;
    }
};