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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values, ans;
        stack<int> s;

        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }

        ans.resize(values.size());
        for (int i = values.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= values[i]) s.pop();

            ans[i] = s.empty() ? 0 : s.top();
            s.push(values[i]);
        }

        return ans;
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
    vector<int> res = sol.nextLargerNodes(head);
    for (int x : res) {
        cout << x << " ";
    }
}

