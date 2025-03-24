#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int res = 0;

    void dfs(TreeNode* root, long long sum) {
        if (!root) return;
        if (root->val == sum) res++;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return res;
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return res;
    }
};