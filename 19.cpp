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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *right = head, *left = head;

        for (int i = 0; i < n; i++) {
            right = right->next;
        }

        if (right == nullptr) {
            head = head->next;
            return head;
        }

        while (right->next != nullptr) {
            left = left->next;
            right = right->next;
        }
        left->next = left->next->next;

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
    ListNode* res = sol.removeNthFromEnd(head, k);
    printList(res);
}

