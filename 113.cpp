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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        dfs(root, targetSum, v);
        return res;
    }

    void dfs(TreeNode* root, int targetSum, vector<int>& v) {
        if (!root) return;
        v.push_back(root->val);
        if (root->left == root->right) {
            if (targetSum == root->val) {
                res.push_back(v);
            }
        }

        if (root->left) dfs(root->left, targetSum - root->val, v);
        if (root->right) dfs(root->right, targetSum - root->val, v);
        v.pop_back();
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(11);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right->left  = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->right->right->left = new TreeNode(5);
    root1->right->right->right = new TreeNode(1);

    Solution sol;
    vector<vector<int>> v = sol.pathSum(root1, 22);
    for (auto x : v) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}   