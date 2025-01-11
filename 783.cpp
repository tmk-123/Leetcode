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
    int diff = INT_MAX;
    TreeNode* prev = nullptr;
    void dfs(TreeNode* root) {
        if (root->left) dfs(root->left);

        if (prev) {
            diff = min(diff, abs(prev->val - root->val));
        }

        prev = root;
        if (root->right) dfs(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return diff;    
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
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    Solution sol;
    cout << sol.minDiffInBST(root1);
}   