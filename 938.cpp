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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        int sum = 0;
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }

        if (root->val > low) {
            sum += rangeSumBST(root->left, low, high);
        }
        if (root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }

        return sum;
    }
};
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(15);
    root1->right->left = new TreeNode(3);
    root1->right->right = new TreeNode(7);

    Solution sol;
    cout << sol.rangeSumBST(root1, 7, 15);
}   