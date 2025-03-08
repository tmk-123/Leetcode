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
    int index = 0;

    TreeNode* dfs(vector<int>& preorder, int upper_bound) {
        if (index >= preorder.size() || preorder[index] > upper_bound) return nullptr;

        TreeNode* newNode = new TreeNode(preorder[index++]);
        newNode->left = dfs(preorder, newNode->val);
        newNode->right = dfs(preorder, upper_bound);

        return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, INT_MAX);
    }
};

int main() {
    vector<int> v = {8,5,1,7,10,9,12};
    Solution sol;
    sol.bstFromPreorder(v);
}