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
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorderTraversal(TreeNode* root) {
        if (!root) return;

        inorderTraversal(root->left);

        if (prev && root->val < prev->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;

        inorderTraversal(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorderTraversal(root);
        swap(first->val, second->val);
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
    root1->left = new TreeNode(3);
    root1->left->right = new TreeNode(2);

    Solution sol;
    sol.recoverTree(root1);
    inorder(root1);
}   