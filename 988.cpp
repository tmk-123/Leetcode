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
    string minString = string(1, 'z' + 1);
    string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        dfs(root, "");
        return minString;
    }

    void dfs(TreeNode* root, string s) {
        if (!root) {
            return;
        }
        s.push_back(root->val + 'a');
        if (!root->left && !root->right) {
            reverse(s.begin(), s.end());
            minString = min(s, minString);
        }
        
        dfs(root->left, s);
        dfs(root->right, s);
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(1);
    root1->left->right = new TreeNode(1);
    root1->left->right->left = new TreeNode(0);
    root1->right->left = new TreeNode(0);

    Solution sol;
    cout << sol.smallestFromLeaf(root1);
}  