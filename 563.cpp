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
    int sumTilt = 0;
    int dfs(TreeNode* root, int& sum) {
        if (!root) return 0;

        int leftSum = dfs(root->left, sum);
        int rightSum = dfs(root->right, sum);

        sum = abs(leftSum - rightSum);
        sumTilt += sum;

        return leftSum + rightSum + root->val;
    }

    int findTilt(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return sumTilt;
    }
};
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << sol.findTilt(root) << endl;

    return 0;
}