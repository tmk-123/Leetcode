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
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;
        return (isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};
int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(4);
    root2->right = new TreeNode(5);

    Solution sol;
    cout << sol.isSubtree(root1, root2) << endl;

    return 0;
}