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

// cây tìm kiếm nhị phân, nếu xuất hiện nhiều lần sẽ liên tiếp nhau
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        int maxFreq = 0, currFreq = 0, prevVal = INT_MIN;
        vector<int> res;
        dfs(root, prevVal, currFreq, maxFreq, res);
        return res;
    }
    void dfs(TreeNode* root, int& prevVal, int& currFreq, int& maxFreq, vector<int>& res) {
        if (!root) return;

        dfs(root->left, prevVal, currFreq, maxFreq, res);

        if (root->val == prevVal) currFreq++;
        else currFreq = 1;
        prevVal = root->val;

        if (currFreq > maxFreq) {
            maxFreq = currFreq; 
            res = {root->val};
        }
        else if (currFreq == maxFreq) res.push_back(root->val);
        
        dfs(root->right, prevVal, currFreq, maxFreq, res);
    }
};
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(2);

    Solution sol;
    vector<int> res = sol.findMode(root1);
    for (int x : res) {
        cout << x << " ";
    }
}   