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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        dfs(root, freq);
        
        int maxFreq = 0;
        for (auto x : freq) {
            maxFreq = max(maxFreq, x.second);
        }

        vector<int> res;
        for (auto x : freq) {
            if (x.second == maxFreq) res.push_back(x.first);
        }

        return res;
    }
    void dfs(TreeNode* root, unordered_map<int, int>& freq) {
        if (!root) return;

        freq[root->val]++;
        dfs(root->left, freq);
        dfs(root->right, freq);
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
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(2);
    root1->right->right = new TreeNode(2);

    Solution sol;
    vector<int> res = sol.findMode(root1);
    for (int x : res) {
        cout << x << " ";
    }
}   