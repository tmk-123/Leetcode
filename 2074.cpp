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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupTail = dummy;
        ListNode* cur = head;
        int groupSize = 1;

        while (cur) {
            ListNode* groupHead = cur;

            int count = 0;
            while (cur != nullptr && count < groupSize) {
                count++;
                cur = cur->next;
            }

            if (count % 2 == 0) {
                ListNode* newGroupHead = reverseGroup(groupHead, cur);
                prevGroupTail->next = newGroupHead;
                groupHead->next = cur;
                prevGroupTail = groupHead;
            }
            else {
                prevGroupTail = groupHead;
                for (int i = 0; i < count; i++) {
                    prevGroupTail = prevGroupTail->next;
                }
            }

            groupSize++;
        }

        return dummy->next;
    }

    ListNode* reverseGroup(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        // không bao gồm tail(tail là nhóm khác r)
        while (cur != tail) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
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
        int value;
        cin >> value;
        insertAtTail(head, tail, value);
    }

    Solution sol;
    ListNode* res = sol.reverseEvenLengthGroups(head);
    printList(res);
}