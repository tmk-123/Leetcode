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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> v;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (cnt % 2 == 1) reverse(v.begin(), v.end());
            res.push_back(v);
            cnt++;
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
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(10);
    root1->right = new TreeNode(4);
    root1->left->left = new TreeNode(3);
    root1->right->left = new TreeNode(7);
    root1->right->right = new TreeNode(9);
    root1->left->left->left = new TreeNode(12);
    root1->left->left->right = new TreeNode(8);
    root1->right->left->left = new TreeNode(6);
    root1->right->right->right = new TreeNode(2);

    Solution sol;
    vector<vector<int>> v = sol.zigzagLevelOrder(root1);
    for (auto x : v) {
        for (int y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
}   