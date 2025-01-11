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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        dfs(root, false, sum);
        return sum;
    }   

    void dfs(TreeNode* root, bool left, int& sum) {
        if (!root->left && !root->right) {
            if (left) sum += root->val;
            return;
        }

        if (root->left) dfs(root->left, true, sum);
        if (root->right) dfs(root->right, false, sum);
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
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    Solution sol;
    cout << sol.sumOfLeftLeaves(root1);
}   