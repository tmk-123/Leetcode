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
    int countGoodNodes(TreeNode* root, int maxVal) {
        if (!root) return 0;

        int good = (root->val >= maxVal) ? 1 : 0;

        maxVal = max(maxVal, root->val);

        good += countGoodNodes(root->left, maxVal);
        good += countGoodNodes(root->right, maxVal);

        return good;
    }
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val);
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
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(3);
    root1->right->left = new TreeNode(1);
    root1->right->right = new TreeNode(5);

    Solution sol;
    cout << sol.goodNodes(root1);
}  