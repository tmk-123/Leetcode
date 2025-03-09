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
    unordered_map<int, int> inorderMap;
    int preIndex = 0;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }
        
        return construct(preorder, 0, n - 1);
    }
    TreeNode* construct(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = inorderMap[rootVal];

        root->left = construct(preorder, left, mid - 1);
        root->right = construct(preorder, mid + 1, right);

        return root;
    }
};