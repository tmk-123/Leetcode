#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void buildParent(TreeNode* root, TreeNode*& nodeStart, int start) {
        if (!root) return;

        if (root->val == start) nodeStart = root;

        if (root->left) {
            parent[root->left] = root;
            buildParent(root->left, nodeStart, start);
        }
        if (root->right) {
            parent[root->right] = root;
            buildParent(root->right, nodeStart, start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* nodeStart = root;
        
        buildParent(root, nodeStart, start);
        queue<TreeNode*> q;
        q.push(nodeStart);
        unordered_set<TreeNode*> visited;
        visited.insert(nodeStart);
        int cnt = -1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                vector<TreeNode*> neighbors = {node->left, node->right, parent[node]};
                for (auto& neighbor : neighbors) {
                    if (neighbor && visited.find(neighbor) == visited.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }
};