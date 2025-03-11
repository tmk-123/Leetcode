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

        if (left.first == right.first) return {left.first + 1, root};
        if (left.first < right.first) return {right.first + 1, right.second};
        return {left.first + 1, left.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};