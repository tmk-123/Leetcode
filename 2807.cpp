#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* h = head;
        while (head && head->next) {
            int gcd = __gcd(head->val, head->next->val);
            ListNode* node = head->next;
            head->next = new ListNode(gcd);
            head->next->next = node;

            head = head->next->next;
        }

        return h;
    }
};