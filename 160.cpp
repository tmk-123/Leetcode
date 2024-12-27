#include<bits/stdc++.h>

using namespace std;

struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            // vì nếu có đoạn trùng nhau thì cả đuôi đằng sau cũng trùng nhau
            // chuyển sang list còn lại để bù chênh lệch độ dài
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        return a;
    }
};

