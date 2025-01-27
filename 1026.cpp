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
    int maxDiff = 0;
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        dfs(root, root->val, root->val);
        return maxDiff;
    }

    void dfs(TreeNode* node, int maxVal, int minVal) {
        if (!node) return;

        maxDiff = max({maxDiff, abs(maxVal - node->val), abs(maxVal - node->val)});

        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        dfs(node->left, maxVal, minVal);
        dfs(node->right, maxVal, minVal);
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->right = new TreeNode(7);
    root1->right->left = new TreeNode(15);

    Solution sol;
    cout << sol.maxAncestorDiff(root1);
}   