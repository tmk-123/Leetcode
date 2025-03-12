#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    vector<int> res;
    int index = 0;

    bool dfs(TreeNode* root, vector<int>& v) {
        if (!root) return true;
        
        if (root->val != v[index]) return false;
        index++;

        if (root->left && root->left->val != v[index]) {
            res.push_back(root->val);
            return dfs(root->right, v) && dfs(root->left, v);
        }

        return dfs(root->left, v) && dfs(root->right, v);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (!dfs(root, voyage)) return {-1};
        return res;
    }
};