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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long leftMost = q.front().second;
            unsigned long long rightMost = q.back().second;

            maxWidth = max(maxWidth, (int)(rightMost - leftMost + 1));

            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();

                // dịch về chỉ số 0 bằng cách -leftMost
                if (node->left) q.push({node->left, 2 * (index - leftMost)});
                if (node->right) q.push({node->right, 2 * (index - leftMost) + 1});
            }
        }
        
        return maxWidth;
    }
};