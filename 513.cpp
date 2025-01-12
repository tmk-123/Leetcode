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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int leftMostVal = root->val;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (i == 0) leftMostVal = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return leftMostVal;
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
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(5);

    Solution sol;
    cout << sol.findBottomLeftValue(root1);
}   