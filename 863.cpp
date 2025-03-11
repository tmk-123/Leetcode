#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    void buildParent(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node) return;

        if (node->left) {
            parent[node->left] = node;
            buildParent(node->left, parent);
        }
        if (node->right) {
            parent[node->right] = node;
            buildParent(node->right, parent);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        buildParent(root, parent);
        
        // xem thăm chưa bởi duyệt cả cha
        unordered_set<TreeNode*> visited; visited.insert(target);
        queue<TreeNode*> q; q.push(target);

        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (level++ == k) break;

            while (size--) {
                TreeNode* curr = q.front(); q.pop();

                vector<TreeNode*> neighbors = {curr->left, curr->right, parent[curr]};
                for (auto& neighbor : neighbors) {
                    if (neighbor && visited.find(neighbor) == visited.end()) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};