#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* prev = nullptr;
        int carry = 0;

        while (!st1.empty() || !st2.empty() || carry) {
            int sum = carry;

            if (!st1.empty()) {
                sum += st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                sum += st2.top();
                st2.pop();
            }

            carry = sum / 10;
            sum %= 10;

            ListNode* newNode = new ListNode(sum);
            newNode->next = prev;
            prev = newNode;
        }

        return prev;
    }
};