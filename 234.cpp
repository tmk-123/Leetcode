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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;

        while (temp != nullptr) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        if (check(v)) return true;
        return false;
    }

    bool check(vector<int> v) {
        int left = 0, right = v.size() - 1;
        while (left < right) {
            if (v[left] != v[right]) return false;
            left++;
            right--;
        }
        return true;
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
    cout << sol.isPalindrome(head);
}

