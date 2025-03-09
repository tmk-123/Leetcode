#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n, 0);
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        dfs(0, labels, visited, ans, adj);
        return ans;
    }

    vector<int> dfs(int node, string& labels, vector<bool>& visited, vector<int>& ans, vector<vector<int>>& adj) {
        visited[node] = true;
        vector<int> count(26, 0);
        
        for (int &neighbor : adj[node]) {
            if (!visited[neighbor]) {
                vector<int> subCount = dfs(neighbor, labels, visited, ans, adj);
                for (int i = 0; i < 26; i++) {
                    count[i] += subCount[i];
                }
            }
        }

        count[labels[node] - 'a']++;
        ans[node] = count[labels[node] - 'a'];
        return count;
    }
};