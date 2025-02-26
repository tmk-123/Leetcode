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
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        // so sánh độ sâu của trái ngoài cùng và phải ngoài cùng
        int leftHeight = Lheight(root);
        int rightHeight = Rheight(root);

        if (leftHeight == rightHeight) return (1 << leftHeight) - 1; // 2^n - 1

        // nếu left và right không có độ sâu bằng nhau thì gốc + trái + phải
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int Lheight(TreeNode* root) {
        int cnt = 0;
        while (root) {
            cnt++;
            root = root->left;
        }
        return cnt;
    }

    int Rheight(TreeNode* root) {
        int cnt = 0;
        while (root) {
            cnt++;
            root = root->right;
        }
        return cnt;
    }
};
