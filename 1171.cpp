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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> prefixSum;
        ListNode* cur = dummy;
        int currentSum = 0;

        while (cur) {
            currentSum += cur->val;

            if (prefixSum.find(currentSum) != prefixSum.end()) {
                ListNode* prev = prefixSum[currentSum];
                ListNode* temp = prev->next;
                int sum = currentSum;
                
                while (temp != cur) {
                    sum += temp->val;
                    prefixSum.erase(sum);
                    temp = temp->next;
                }
                prev->next = cur->next;
            }
            else {
                prefixSum[currentSum] = cur;
            }

            cur = cur->next;
        }

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
    ListNode* res = sol.removeZeroSumSublists(list1);
    printList(res);
}
