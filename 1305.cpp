#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        dfs(root1, v1);
        dfs(root2, v2);

        vector<int> res;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) res.push_back(v1[i++]);
            else res.push_back(v2[j++]);
        }
        
        while (i < v1.size()) res.push_back(v1[i++]);
        while (j < v2.size()) res.push_back(v2[j++]);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& v) {
        if (!root) return;

        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
}; 