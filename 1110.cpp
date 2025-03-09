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
    vector<TreeNode*> res;
    unordered_set<int> setDelete;

    TreeNode* dfs(TreeNode* node, bool isRoot) {
        if (!node) return nullptr;
        
        bool toDelete = setDelete.count(node->val);
        // nếu là gốc(hoặc gốc mới), tức cha của nó bị xóa và nút đấy không bị xóa
        if (isRoot && !toDelete) res.push_back(node);

        node->left = dfs(node->left, toDelete);
        node->right = dfs(node->right, toDelete);

        return toDelete ? nullptr : node;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        setDelete = unordered_set<int>(to_delete.begin(), to_delete.end());
        dfs(root, true);
        return res;
    }
};