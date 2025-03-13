#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encode(root);
    }

    string encode(TreeNode* root) {
        if (!root) return "";
        return to_string(root->val) + "-" + encode(root->left) + encode(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string s;
        TreeNode* root = nullptr;

        while (getline(ss, s, '-')) {
            root = insert(root, stoi(s));
        }

        return root;
    }

    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
    
        if (val <= root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
    
        return root;
    }
};