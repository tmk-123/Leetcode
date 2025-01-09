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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode* res = new TreeNode(root->val);
        dfs(res, root);
        return res;
    }
    void dfs(TreeNode* res, TreeNode* root) {
        if (!root) return;
        if (root->left) res->right = new TreeNode(root->left->val);
        if (root->right) res->left = new TreeNode(root->right->val);

        dfs(res->left, root->right);
        dfs(res->right, root->left);
    }
};
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(1);
    root1->right->left = new TreeNode(3);
    root1->right->right = new TreeNode(4);
    root1->left->left->left = new TreeNode(3);
    root1->left->left->right = new TreeNode(1);
    Solution sol;
    inorder(sol.invertTree(root1));
}   