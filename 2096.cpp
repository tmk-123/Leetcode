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
    TreeNode* findLCA(TreeNode* root, int start, int dest) {
        if (!root || root->val == start || root->val == dest) return root;
        
        TreeNode* left = findLCA(root->left, start, dest);
        TreeNode* right = findLCA(root->right, start, dest);

        if (left && right) return root;
        if (left) return left;
        return right;
    }
    bool getPath(TreeNode* curr, int target, string& path) {
        if (!curr) return false;
        if (curr->val == target) return true;

        path.push_back('L');
        if (getPath(curr->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (getPath(curr->right, target, path)) return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = findLCA(root, startValue, destValue);

        string pathToStart, pathToDest;
        getPath(LCA, startValue, pathToStart);
        getPath(LCA, destValue, pathToDest);

        for (char& c : pathToStart) c = 'U';
        return pathToStart + pathToDest;
    }
};