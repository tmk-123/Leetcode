#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            if (level % 2 == 1) {
                queue<TreeNode*> temp = q;
                vector<int> v;
                while (size--) {
                    TreeNode* node = temp.front(); temp.pop();
                    v.push_back(node->val);

                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }

                for (int i = v.size() - 1; i >= 0; i--) {
                    TreeNode* node = q.front(); q.pop();
                    node->val = v[i];
                }
            }
            else {
                while (size--) {
                    TreeNode* node = q.front(); q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            level++;
        }

        return root;
    }
};