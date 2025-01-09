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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        int secondMin = -1;
        dfs(root, secondMin, root->val);
        return secondMin;
    }

    void dfs(TreeNode* root, int& secondMin, int smallest) {
        if (!root) return;

        if (root->val > smallest) {
            if (secondMin == -1 || root->val < secondMin) {
                secondMin = root->val;
            }
        }

        dfs(root->left, secondMin, smallest);
        dfs(root->right, secondMin, smallest);
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
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(1);
    root1->right->left = new TreeNode(3);
    root1->right->right = new TreeNode(4);
    root1->left->left->left = new TreeNode(3);
    root1->left->left->right = new TreeNode(1);
    Solution sol;
    cout << sol.findSecondMinimumValue(root1);
}   