#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    vector<int> v;
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);
        sort(v.rbegin(), v.rend());
        if (v.size() < k) return -1;
        return v[k - 1];
    }

    pair<int, bool> dfs(TreeNode* root) {
        if (!root) return {0, true};

        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        if (left.first != right.first) return {left.first + right.first + 1, false};
        
        if (left.second && right.second) v.push_back(left.first + right.first + 1);   
        return {left.first + right.first + 1, left.second && right.second};
    }
};