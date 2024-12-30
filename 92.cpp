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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        ListNode* temp = head;

        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        left--;
        right--;
        while (left < right) {
            swap(v[left], v[right]);
            left++;
            right--;
        }

        ListNode* t = head;
        for (int i = 0; i < v.size(); i++) {
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
    int n, l, r;
    cin >> n >> l >> r;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(head, tail, value);
    }

    Solution sol;
    ListNode* res = sol.reverseBetween(head, l, r);
    printList(res);
}