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
    vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return {};
        if (!node->left && !node->right) return {1};
        
        // khoảng cách từng lá một của trái, phải
        vector<int> left_distance = dfs(node->left, distance, result);
        vector<int> right_distance = dfs(node->right, distance, result);

        for (int l : left_distance) {
            for (int r : right_distance) {
                if (l + r <= distance) result++;
            }
        }

        // phần nào khoảng cách chắc chắn lớn hơn distance thì bỏ luôn
        vector<int> merged;
        for (int l : left_distance) {
            if (l + 1 < distance) merged.push_back(l + 1);
        }
        for (int r : right_distance) {
            if (r + 1 < distance) merged.push_back(r + 1);
        }
        return merged;
    }

    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
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
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);
    root1->right->right = new TreeNode(7);

    Solution sol;
    cout << sol.countPairs(root1, 3);
}  