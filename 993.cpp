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
    int depthX = -1, depthY = -1;
    TreeNode* parentX = nullptr;
    TreeNode* parentY = nullptr;

    void dfs(TreeNode* node, TreeNode* parent, int depth, int x, int y) {
        if (!node) return;

        if (node->val == x) {
            depthX = depth;
            parentX = parent;
        }

        if (node->val == y) {
            depthY = depth;
            parentY = parent;
        }

        dfs(node->left, node, depth + 1, x, y);
        dfs(node->right, node, depth + 1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, 0, x, y);
        return (depthX == depthY) && (parentX != parentY);
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
int main() {
    vector<int> nodes1 = {1, 2, 3, -1, 4, -1, 5};
    TreeNode* root1 = createTree(nodes1);
    Solution sol;
    cout << sol.isCousins(root1, 4, 5);
}
