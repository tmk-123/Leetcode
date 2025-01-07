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
    int sum = 0;
    void dfs(TreeNode* node, TreeNode* parent, int n) {
        if (!node) {
            if (!parent->left && !parent->right) {
                sum += n;
            }
            return;
        }

        dfs(node->left, node, n * 2 + node->val);
        dfs(node->right, node, n * 2 + node->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, nullptr, 0);
        return sum / 2;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(1);

    Solution sol;
    cout << sol.sumRootToLeaf(root) << endl;

    return 0;
}