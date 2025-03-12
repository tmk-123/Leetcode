#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    unordered_map<int, int> freqSum;
    int maxFreq = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);

        int sum = left + right + root->val;
        freqSum[sum]++;
        maxFreq = max(maxFreq, freqSum[sum]);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        dfs(root);
        for (auto& [sum, freq] : freqSum) {
            if (freq == maxFreq) res.push_back(sum); 
        }
        return res;
    }
};