#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* findMid(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;    
            fast = fast->next->next;
        }

        if (prev) prev->next = nullptr;

        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* head = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            head = merge(head, lists[i]);
        }        
        return head;
    }
};