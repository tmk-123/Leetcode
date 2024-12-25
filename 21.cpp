#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // tạo node giả bắt có giá trị -1, trỏ tới null làm điểm bắt đầu, xong thì xóa nút giả đi
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy; // bắt đầu từ nút -1

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr) current->next = list1;
        else current->next = list2;

        ListNode* res = dummy->next; // danh sách bắt đầu từ dummy->next
        delete dummy;
        return res;
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
    int n, m;
    cin >> n >> m;

    ListNode* list1 = nullptr;
    ListNode* tail1 = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(list1, tail1, value);
    }

    ListNode* list2 = nullptr;
    ListNode* tail2 = nullptr;

    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        insertAtTail(list2, tail2, value);
    }

    Solution sol;
    ListNode* res = sol.mergeTwoLists(list1, list2);
    printList(res);
}
