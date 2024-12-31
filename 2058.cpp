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
        vector<int> v;

        while (head->next) {
            if ((prev->val < head->val && head->next->val < head->val) ||
                (prev->val > head->val && head->next->val > head->val)) {
                    v.push_back(1);
                }
            else v.push_back(0);

            prev = head;
            head = head->next;
        }

        int minDistance = -1, maxDistance = -1;

        int left = 0, right = v.size() - 1;
        while (left < right) {
            if (v[left] == 1 && v[right] == 1) {
                maxDistance = right - left;
                break;
            }
            if (v[left] == 0) left++;
            if (v[right] == 0) right--;
        }
        
        if (maxDistance == -1) return {-1, -1};

        for (int i = left + 1; i < v.size(); i++) {
            if (v[i] == 1) {
                if (minDistance != -1) minDistance = min(minDistance, i - left);
                else minDistance = i - left;
                left = i;
            }
        } 

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