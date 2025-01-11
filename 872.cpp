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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        findLeaf(root1, v1);
        findLeaf(root2, v2);
        return v1 == v2;
    }

    void findLeaf(TreeNode* root, vector<int>& leaf) {
        if (!root) return;

        if (!root->left && !root->right) leaf.push_back(root->val);
        findLeaf(root->left, leaf);
        findLeaf(root->right, leaf);
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
    root1->left = new TreeNode(1);
    root1->left->left = new TreeNode(5);
    root1->right = new TreeNode(2);
    
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->right->right = new TreeNode(2);

    Solution sol;
    cout << sol.leafSimilar(root1, root2);
}   