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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;

        for (int x : queries) {
            int minX = -1, maxX = -1;
            dfsMin(root, x, minX);
            dfsMax(root, x, maxX);
            res.push_back({minX, maxX});
        }

        return res;
    }

    void dfsMin(TreeNode* root, int x, int& minX) {
        if (!root) return;
        
        dfsMin(root->left, x, minX);
        if (root->val <= x) {
            minX = root->val;
        }
        dfsMin(root->right, x, minX);
    }
    void dfsMax(TreeNode* root, int x, int& maxX) {
        if (!root) return;
        
        dfsMax(root->right, x, maxX);
        if (root->val >= x) {
            maxX = root->val;
        }
        dfsMax(root->left, x, maxX);
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(6);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(13);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(15);
    root1->right->right->left = new TreeNode(14);

    Solution sol;
    vector<int> q = {2, 5, 16};
    vector<vector<int>> res = sol.closestNodes(root1, q);
    for (auto v : res) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}   