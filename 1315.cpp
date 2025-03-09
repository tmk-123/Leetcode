#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sum = 0;
    void dfs(TreeNode* root, TreeNode* parent) {    
        if (!root) return;   
        if (root->left) {
            if (parent->val % 2 == 0) sum += root->left->val;
            dfs(root->left, root);
        } 
        if (root->right) {
            if (parent->val % 2 == 0) sum += root->right->val;
            dfs(root->right, root);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        dfs(root->left, root);
        dfs(root->right, root);
        return sum;
    }
};