#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool foundNull = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) foundNull = true;
            else {
                if (foundNull) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return true;
    }
};