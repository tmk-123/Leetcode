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
    ListNode* doubleIt(ListNode* head) {
        if (head->val == 0) return new ListNode(0);
        ListNode* temp = head;
        stack<int> st;

        while (temp) {
            st.push(temp->val);
            temp = temp->next;
        }

        int remainder = 0;
        ListNode* prev = nullptr;
        while (!st.empty()) {
            int x = st.top() * 2 + remainder;
            remainder = x / 10;
            ListNode* cur = new ListNode(x % 10);
            cur->next = prev;
            prev = cur;
            st.pop();
        }
        if (remainder > 0) {
            ListNode* cur = new ListNode(remainder);
            cur->next = prev;
            prev = cur;
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

    ListNode* list1 = nullptr;
    ListNode* tail1 = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(list1, tail1, value);
    }

    Solution sol;
    ListNode* res = sol.doubleIt(list1);
    printList(res);
}
