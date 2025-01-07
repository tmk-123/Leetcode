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
    int minDep = INT_MAX;
    void dfs(TreeNode* root, TreeNode* parent, int n) {
        if (!root) {
            if (!parent->left && !parent->right) {
                minDep = min(minDep, n);
            }
            return;
        }
        dfs(root->left, root, n + 1);
        dfs(root->right, root, n + 1);
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        dfs(root, nullptr, 0);
        return minDep;
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
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    Solution sol;
    cout << sol.minDepth(root1);

    return 0;
}