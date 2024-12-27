#include<bits/stdc++.h>

using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr || (head->next == nullptr && head->val == val)) return nullptr;
        ListNode* current = new ListNode(-1);
        current->next = head;
        ListNode* res = current;

        while (current != nullptr && current->next != nullptr) {
            if (current->next->val == val) {
                current->next = current->next->next;
            }
            else current = current->next;
        }

        res = res->next;
        return res;
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
    int val;
    cin >> val;

    int n;
    cin >> n;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtTail(head, tail, val);
    }

    Solution sol;
    ListNode* res = sol.removeElements(head, val);
    printList(res);
}

