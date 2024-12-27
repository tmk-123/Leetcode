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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* temp = head;
        vector<int> v;

        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;    
        }

        ListNode* t = head;
        for (int i = v.size() - 1; i >= 0; i--) {
            t->val = v[i];
            t = t->next;
        }

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
    ListNode* res = sol.reverseList(head);
    printList(res);
}

