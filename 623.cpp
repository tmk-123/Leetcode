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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        return add(root, val, depth, 1);
    }

    TreeNode* add(TreeNode* root, int val, int depth, int currDepth) {
        if (!root) return nullptr;  

        if (currDepth == depth - 1) {
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = leftTemp;
            root->right->right = rightTemp;

            return root;
        }

        root->left = add(root->left, val, depth, currDepth + 1);
        root->right = add(root->right, val, depth, currDepth + 1);

        return root;
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
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(11);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right->left  = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->right->right->left = new TreeNode(5);
    root1->right->right->right = new TreeNode(1);

    Solution sol;
    inorder(sol.addOneRow(root1, 1, 2));
}   