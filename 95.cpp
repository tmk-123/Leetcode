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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return Try(1, n);
    }

    vector<TreeNode*> Try(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
        }

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftNode = Try(start, i - 1);
            vector<TreeNode*> rightNode = Try(i + 1, end);

            for (auto left : leftNode) {
                for (auto right : rightNode) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    int n;
    cin >> n;
    Solution sol;
    vector<TreeNode*> res = sol.generateTrees(n);
    for (auto x : res) {
        inorder(x);
        cout << endl;
    }
}   