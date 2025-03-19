#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> Set(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;

        while (curr && curr->next) {
            while (curr->next && Set.find(curr->next->val) != Set.end()) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};