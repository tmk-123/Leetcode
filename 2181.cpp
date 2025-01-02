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
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int sum = 0;

        while (head) {
            if (head->val == 0) {
                ListNode* newNode = new ListNode(sum);
                cur->next = newNode;
                cur = cur->next;
                sum = 0;
            } 
            else {
                sum += head->val;
            }

            head = head->next;
        }
        cur->next = nullptr;
        
        return dummy->next;
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

    ListNode* list1 = nullptr;
    ListNode* tail1 = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(list1, tail1, value);
    }

    Solution sol;
    ListNode* res = sol.mergeNodes(list1);
    printList(res);
}
