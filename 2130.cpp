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
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* cur = head;

        while (cur) {
            v.push_back(cur->val);
            cur = cur->next;
        }

        int n = v.size();
        int maxSum = 0;
        for (int i = 0; i < n / 2; i++) {
            maxSum = max(maxSum, v[i] + v[n - i - 1]);
        }

        return maxSum;
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
    int res = sol.pairSum(head);
    cout << res;
}