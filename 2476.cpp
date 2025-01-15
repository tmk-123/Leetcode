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
        vector<int> v;
        inorderTraversal(root, v);

        for (int q : queries) {
            auto it1 = upper_bound(v.begin(), v.end(), q);
            int mini = (it1 == v.begin()) ? -1 : *(--it1);

            auto it2 = lower_bound(v.begin(), v.end(), q);
            int maxi = (it2 == v.end()) ? -1 : *it2;

            res.push_back({mini, maxi});
        }
        return res;
    }
    void inorderTraversal(TreeNode* root, vector<int>& v) {
        if (!root) return;
        inorderTraversal(root->left, v);
        v.push_back(root->val);
        inorderTraversal(root->right, v);
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