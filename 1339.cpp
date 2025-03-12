#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    const int mod = 1e9 + 7;
    long long totalSum = 0, max_product = 0;

    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    int findMaxProduct(TreeNode* root) {
        if (!root) return 0;

        int subtreeSum = root->val + findMaxProduct(root->left) + findMaxProduct(root->right);
        max_product = max(max_product, (totalSum - subtreeSum) * (long long)subtreeSum);
        return subtreeSum;
    }
    
    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        findMaxProduct(root);
        return max_product % mod;    
    }
};