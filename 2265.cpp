#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    int cnt = 0;

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return cnt;
    }

    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int sum = left.first + right.first + node->val;
        int countNodes = left.second + right.second + 1;

        if (sum / countNodes == node->val) cnt++;
        return {sum, countNodes};
    }
};