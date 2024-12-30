#include<bits/stdc++.h>

using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
};
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev) prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};

void printTreeNode(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printTreeNode(root->left);
    printTreeNode(root->right);
}
int main() {
    int n;
    cin >> n;
    ListNode* head = new ListNode(0);
    ListNode* temp = head;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        temp->next = new ListNode(value);
        temp = temp->next;
    }

    Solution sol;
    TreeNode* res = sol.sortedListToBST(head->next);
    printTreeNode(res);
}

