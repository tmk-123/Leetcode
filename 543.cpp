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
    int dfs(TreeNode* root, int& n) {
        if (!root) {
            return 0;
        }

        int left = dfs(root->left, n);
        int right = dfs(root->right, n);

        n = max(n, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int n = 0;
        dfs(root, n);
        return n;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}