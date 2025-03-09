#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtreeCount;
        vector<TreeNode*> res;
        dfs(root, subtreeCount, res);
        return res;
    }
    string dfs(TreeNode* root, unordered_map<string, int>& subtreeCount, vector<TreeNode*>& res) {
        if (!root) return "#";

        string subtree = to_string(root->val) + "," +
                        dfs(root->left, subtreeCount, res) + "," +
                        dfs(root->right, subtreeCount, res);

        if (++subtreeCount[subtree] == 2) res.push_back(root);
        return subtree;
    }
};