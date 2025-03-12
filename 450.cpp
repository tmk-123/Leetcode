#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (root->val < key) root->right = deleteNode(root->right, key);
        else if (root->val > key) root->left = deleteNode(root->left, key);
        else {
            if (!root->left && !root->right) return nullptr;
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // nếu có hai nút con thì tìm node nhỏ nhất trong cây bên phải hoặc lớn nhất trong cây con trái
            TreeNode* temp = root->left;
            while (temp->right) {
                temp = temp->right;
            }
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val); // xóa nốt vừa lấy giá trị đi
        }

        return root;
    }
};