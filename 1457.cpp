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
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int path) {
        if (!root) return 0;

        path ^= (1 << root->val);
        if (!root->left && !root->right) {
            return (__builtin_popcount(path) <= 1) ? 1 : 0;
        }

        return dfs(root->left, path) + dfs(root->right, path);
    }
};