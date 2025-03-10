#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class FindElements {
public:
    unordered_set<int> nodeVal;
    void dfs(TreeNode* root) {
        nodeVal.insert(root->val);

        if (root->left) {
            root->left->val = 2 * root->val + 1;
            dfs(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            dfs(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val = 0;
        dfs(root);
    }
    
    bool find(int target) {
        if (nodeVal.find(target) != nodeVal.end()) return true;
        return false;
    }
};