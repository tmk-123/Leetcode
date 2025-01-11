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
    bool evaluateTree(TreeNode* root) {
        if (!root->left) {
            if (root->val == 0) return false;
            return true;
        }
        if (root->left) {
            if (root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
            else return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(1);
    Solution sol;
    cout << sol.evaluateTree(root1);
}   