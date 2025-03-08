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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int m = height + 1, n = pow(2, height + 1) - 1;
        vector<vector<string>> v(m, vector<string>(n, ""));
        fillMatrix(root, v, 0, (n - 1) / 2, height);
        return v;
    }
    
    int getHeight(TreeNode* root) {
        if (!root) return -1;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    void fillMatrix(TreeNode* root, vector<vector<string>>& v, int r, int c, int height) {
        if (!root) return;
        
        v[r][c] = to_string(root->val);
        int x = pow(2, height - r - 1);
        fillMatrix(root->left, v, r + 1, c - x, height);
        fillMatrix(root->right, v, r + 1, c + x, height);
    }
};