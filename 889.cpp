#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    unordered_map<int, int> postorderMap;
    int preorderIndex = 0;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            postorderMap[postorder[i]] = i;
        }

        return dfs(preorder, 0, preorder.size() - 1);
    }

    TreeNode* dfs(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        

        if (preorderIndex < preorder.size()) {
            int postorderIndex = postorderMap[preorder[preorderIndex]];
            if (postorderIndex <= right) {
                root->left = dfs(preorder, left, postorderIndex);
                root->right = dfs(preorder, postorderIndex + 1, right - 1);
            }
        }
        return root;
    }
};