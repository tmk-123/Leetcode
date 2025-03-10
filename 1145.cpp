#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int leftCount, rightCount;

    int countNodes(TreeNode* root, int x) {
        if (!root) return 0;

        int left = countNodes(root->left, x);
        int right = countNodes(root->right, x);

        if (root->val == x) {
            leftCount = left;
            rightCount = right;
        }

        return left + right + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        leftCount = rightCount = 0;

        int totalCount = countNodes(root, x);
        int parentCount = n - (leftCount + rightCount + 1);

        int maxPart = max({parentCount, leftCount, rightCount});
        return maxPart > n / 2;
    }
};