#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int total = 0;
        dfs(1, cost, total);
        return total;
    }

    int dfs(int node, vector<int>& cost, int& total) {
        if (node > cost.size()) return 0;

        int left = dfs(node * 2, cost, total);
        int right = dfs(node * 2 + 1, cost, total);

        total += abs(left - right);

        return max(left, right) + cost[node - 1];
    }
};