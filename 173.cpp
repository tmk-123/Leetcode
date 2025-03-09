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

class BSTIterator {
public: 
    stack<TreeNode*> st;
    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (node->right) pushLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};