#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, root};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int leftDepth = left.first, rightDepth = right.first;

        if (leftDepth == rightDepth) return {leftDepth + 1, root};
        else if (leftDepth < rightDepth) return {rightDepth + 1, right.second};
        return {leftDepth + 1, left.second};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};