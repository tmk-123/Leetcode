#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxLen = 0;

    int dfs(vector<vector<int>>& adj, string& s, int node) {
        int max1 = 0, max2 = 0;

        for (int& child : adj[node]) {
            int childlen = dfs(adj, s, child);
            
            if (s[child] != s[node]) {
                if (childlen > max1) {
                    max2 = max1;
                    max1 = childlen;
                }
                else if (childlen > max2) max2 = childlen;
            }
        }

        maxLen = max(maxLen, max1 + max2 + 1);
        return max1 + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs(adj, s, 0);
        return maxLen;
    }
};