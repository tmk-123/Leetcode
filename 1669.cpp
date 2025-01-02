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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        int cnt = 0;
        ListNode* prevTail = nullptr;
        while (cnt < a - 1) {
            cnt++;
            temp = temp->next;
        }

        prevTail = temp;
        ListNode* removeHead = temp->next;
        cnt++;
        temp->next = list2;

        while (cnt < b) {
            cnt++;
            removeHead = removeHead->next;
        }
        
        while (1) {
            if (temp->next == nullptr) {
                temp->next = removeHead->next;
                break;
            }
            temp = temp->next;
        }

        return list1;
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

    int a, b;
    cin >> a >> b;

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
    ListNode* res = sol.mergeInBetween(list1, a, b, list2);
    printList(res);
}
