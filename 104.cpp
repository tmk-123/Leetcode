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
    int maxDep = 0;
    void recursion(TreeNode* root, int depth) {
        if (!root) {
            maxDep = max(maxDep, depth);
            return;
        }
        recursion(root->left, depth + 1);
        recursion(root->right, depth + 1);  
    }
    int maxDepth(TreeNode* root) {
        recursion(root, 0);
        return maxDep;
    }
};
int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    Solution sol;
    cout << sol.maxDepth(root1) << endl;

    return 0;
}