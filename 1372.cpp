#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPath = 0;
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        if (root->left) dfs(root->left, root, 1);
        if (root->right) dfs(root->right, root, 1); 
        return maxPath;
    }

    void dfs(TreeNode* root, TreeNode* parent, int path) {
        if (!root) return;

        if (root == parent->left) {
            dfs(root->right, root, path + 1);
            dfs(root->left, root, 0);
            maxPath = max(maxPath, path);
        }
        else {
            dfs(root->left, root, path + 1);
            dfs(root->right, root, 0);
            maxPath = max(maxPath, path);
        }
    }
};