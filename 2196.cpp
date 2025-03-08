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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto &x : descriptions) {
            int parent = x[0], child = x[1], isLeft = x[2];

            if (nodes.find(parent) == nodes.end()) nodes[parent] = new TreeNode(parent);
            if (nodes.find(child) == nodes.end()) nodes[child] = new TreeNode(child);

            if (isLeft) nodes[parent]->left = nodes[child];
            else nodes[parent]->right = nodes[child];
            
            children.insert(child);
        }

        for (auto& node : nodes) {
            if (children.find(node.first) == children.end()) {
                return node.second;
            }
        }
        return nullptr;
    }
};