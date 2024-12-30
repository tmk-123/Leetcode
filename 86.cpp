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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(-101);
        ListNode* dummy2 = new ListNode(-101);
        ListNode *cur1 = dummy1, *cur2 = dummy2;

        ListNode* temp = head;

        while (temp) {
            if (temp->val < x) {
                cur1->next = temp;
                cur1 = cur1->next;
            }
            else {
                cur2->next = temp;
                cur2 = cur2->next;
            }
            temp = temp->next;
        }
        
        cur1->next = dummy2->next;
        cur2->next = nullptr;

        return dummy1->next;
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
    ListNode* res = sol.partition(head, k);
    printList(res);
}