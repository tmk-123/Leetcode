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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode* current = head;

        int len = 1;
        while (current->next) {
            current = current->next;
            len++;
        }  

        current->next = head; // noi dau voi cuoi

        k %= len;
        if (k == 0) {
            current->next = nullptr;
            return head;    
        }

        ListNode* newTail = head;
        for (int i = 1; i < len - k; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
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
        int value;
        cin >> value;
        insertAtTail(head, tail, value);
    }

    Solution sol;
    ListNode* res = sol.rotateRight(head, k);
    printList(res);
}