#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head, root, false);
    }

    bool dfs(ListNode* head, TreeNode* root, bool found) {
        if (!head) return true;
        if (!root) return false;

        if (root->val == head->val) {
            if (dfs(head->next, root->left, true) || dfs(head->next, root->right, true)) return true;
        }

        if (found) return false;
        return dfs(head, root->left, found) || dfs(head, root->right, found);
    }
};