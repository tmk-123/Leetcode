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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return {-1, -1};

        ListNode* prev = head;
        head = head->next;
        int index = 2;
        vector<int> v;

        while (head->next) {
            if ((prev->val < head->val && head->next->val < head->val) ||
                (prev->val > head->val && head->next->val > head->val)) {
                    v.push_back(index);
                }

            prev = head;
            head = head->next;
            index++;
        }

        if (v.size() < 2) return {-1, -1};

        int minDistance = INT_MAX, maxDistance = v[v.size() - 1] - v[0];
        for (int i = 1; i < v.size(); i++) minDistance = min(minDistance, v[i] - v[i - 1]);
        
        return {minDistance, maxDistance};
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
        int value;
        cin >> value;
        insertAtTail(head, tail, value);
    }

    Solution sol;
    vector<int> res = sol.nodesBetweenCriticalPoints(head);
    for (int i : res) {
        cout << i << " ";
    }
}