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
    int moves = 0;

    int distributeCoins(TreeNode* root) {
        if (!root) return 0;

        int leftExcess = distributeCoins(root->left);
        int rightExcess = distributeCoins(root->right);

        moves += abs(leftExcess) + abs(rightExcess);

        return root->val - 1 + leftExcess + rightExcess;
    }

    int distributeCoinsMain(TreeNode* root) {
        distributeCoins(root);
        return moves;
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
    cout << sol.distributeCoins(root1);
}  