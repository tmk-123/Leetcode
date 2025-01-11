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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;

        queue<int> q;
        dfs(root, q);
        TreeNode* newRoot = new TreeNode(q.front());
        TreeNode* cur = newRoot;
        q.pop();

        while (!q.empty()) {
            cur->left = nullptr;
            cur->right = new TreeNode(q.front());
            q.pop();
            cur = cur->right; 
        }

        return newRoot;
    }

    void dfs(TreeNode* root, queue<int>& q) {
        if (!root) return;

        dfs(root->left, q);
        q.push(root->val);
        dfs(root->right, q);
    }
};
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    Solution sol;
    TreeNode* res = sol.increasingBST(root1);
    inorder(res);
} 