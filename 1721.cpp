#include<bits/stdc++.h>

using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left = head, *right = head;
        for (int i = 0; i < k - 1; i++) {
            right = right->next;
        }
        
        ListNode* first = right;
        while (right->next != nullptr) {
            right = right->next;
            left = left->next;
        }

        swap(first->val, left->val);
        return head;
    }
};
void insertAtTail(ListNode*& head, ListNode*& tail, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtTail(head, tail, val);
    }

    Solution sol;
    ListNode* res = sol.swapNodes(head, k);
    printList(res);
}

