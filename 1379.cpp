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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) return nullptr;
        if (original == target) return cloned;

        TreeNode* left = getTargetCopy(original->left, cloned->left, target);
        if (left != nullptr) return left;
        return getTargetCopy(original->right, cloned->right, target);
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(6);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(13);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(6);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(13);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(4);

    Solution sol;
    inorder(sol.getTargetCopy(root1, root2, root1->left));
}   