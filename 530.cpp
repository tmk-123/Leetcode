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
    int diff = INT_MAX;
    TreeNode* prev = nullptr;
    void dfs(TreeNode* root) {
        if (root->left) dfs(root->left);

        if (prev) {
            diff = min(diff, abs(prev->val - root->val));
        }

        prev = root;
        if (root->right) dfs(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return diff;    
    }
};  
TreeNode* createTree(vector<int> nodes) {
    if (nodes.empty()) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    // hàng đợi để duyệt cùng độ sâu
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (nodes[i] != -1) {
            cur->left = new TreeNode(nodes[i]);
            q.push(cur->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            cur->right = new TreeNode(nodes[i]);
            q.push(cur->right);
        }
        i++;
    }

    return root;
}

