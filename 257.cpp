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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        string s = "";
        dfs(root, res, s);
        return res;
    }

    void dfs(TreeNode* root, vector<string>& res, string s) {
        s += to_string(root->val) + "->" ;
        if (!root->left && !root->right) {
            s.pop_back();
            s.pop_back();
            res.push_back(s);
        }
        if (root->left) dfs(root->left, res, s);
        if (root->right) dfs(root->right, res, s);
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
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(1);
    root1->right->left = new TreeNode(3);
    root1->right->right = new TreeNode(4);
    root1->left->left->left = new TreeNode(3);
    root1->left->left->right = new TreeNode(1);
    Solution sol;
    vector<string> res = sol.binaryTreePaths(root1);
    for (string x : res) {
        cout << x << endl;
    }
}   