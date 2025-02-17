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
        TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val); // Nếu cây rỗng, tạo một nút mới
    
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);  // Chèn vào cây con trái
        } else {
            root->right = insertIntoBST(root->right, val); // Chèn vào cây con phải
        }
    
        return root; // Trả về gốc của cây
    }
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    Solution sol;
    inorder(sol.insertIntoBST(root1, 8));
}   