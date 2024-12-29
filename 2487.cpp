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
    ListNode* removeNodes(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> st;

        while (cur != nullptr) {
            while (!st.empty() && st.top()->val < cur->val) {
                st.pop();
            }

            st.push(cur);
            cur = cur->next;
        }

        ListNode* next = nullptr;
        // lấy các node ngược lại
        while (!st.empty()) {
            cur = st.top();
            st.pop();
            cur->next = next;
            next = cur;
        } 

        return cur;
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
    ListNode* res = sol.removeNodes(head);
    printList(res);
}