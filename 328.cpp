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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *prevOdd = head;
        ListNode* dummy = head->next;
        ListNode *prevEven = head->next; 
        ListNode* temp = head->next->next;

        int cnt = true;
        while (temp) {
            if (cnt) {
                prevOdd->next = temp;
                prevOdd = prevOdd->next;
            }
            else {
                prevEven->next = temp;
                prevEven = prevEven->next;
            }

            cnt = !cnt;
            temp = temp->next;
        }

        prevOdd->next = dummy;
        prevEven->next = nullptr;
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

    ListNode* list1 = nullptr;
    ListNode* tail1 = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(list1, tail1, value);
    }

    Solution sol;
    ListNode* res = sol.oddEvenList(list1);
    printList(res);
}
