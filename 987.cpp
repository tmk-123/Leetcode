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

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> columnTable; // col, row, val
        queue<pair<TreeNode*, pair<int, int>>> q; // node, col, row
        q.push({root, {0, 0}});

        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> curr = q.front();
            TreeNode* node = curr.first;
            q.pop();
            int col = curr.second.first;
            int row = curr.second.second;

            columnTable[col].push_back({row, node->val});

            if (node->left) q.push({node->left, {col - 1, row + 1}});
            if (node->right) q.push({node->right, {col + 1, row + 1}});
        }

        vector<vector<int>> res;
        for (auto x : columnTable) {
            vector<pair<int, int>> v = x.second;

            sort(v.begin(), v.end(), compare);

            vector<int> col;
            for (auto i : v) {
                col.push_back(i.second);
            }
            res.push_back(col);
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
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> res = sol.verticalTraversal(root1);
}   