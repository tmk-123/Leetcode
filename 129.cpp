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
    int sum = 0;
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* root, int s) {
        if (!root) {
            return;
        }

        if (!root->left && !root->right) {
            s = s * 10 + root->val;
            sum += s;
        }
        dfs(root->left, s * 10 + root->val);
        dfs(root->right, s * 10 + root->val);
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(2);
    root1->left->right->right = new TreeNode(3);
    root1->right->left = new TreeNode(5);
    root1->right->right = new TreeNode(7);
    root1->right->right->right = new TreeNode(8);

    Solution sol;
    cout << sol.sumNumbers(root1);
}   