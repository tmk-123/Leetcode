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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int maxLen = 0;
        dfs(root, maxLen);
        return maxLen;
    }

    int dfs(TreeNode* root, int& maxLen) {
        if (!root) return 0;

        int left = dfs(root->left, maxLen);
        int right = dfs(root->right, maxLen);

        int leftPath = 0, rightPath = 0;
        if (root->left && root->left->val == root->val) leftPath = left + 1;
        if (root->right && root->right->val == root->val) rightPath = right + 1;

        maxLen = max(maxLen, leftPath + rightPath);
        return max(leftPath, rightPath);
    }
};
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(1);
    root1->right->right = new TreeNode(5);

    Solution sol;
    cout << sol.longestUnivaluePath(root1);
}   