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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* current = head;
        while (current) {
            n++;
            current = current->next;
        }

        int partSize = n / k;
        int extraNodes = n % k;

        vector<ListNode*> res(k, nullptr);
        current = head;

        for (int i = 0; i < k && current; i++) {
            res[i] = current;
            // mỗi node hơn kém tối đa 1 phần tử và phần nhiều hơn ở đầu
            int currentSize = partSize + (extraNodes > 0 ? 1 : 0);
            extraNodes--;

            for (int j = 1; j < currentSize; j++) {
                current = current->next;
            }

            ListNode* nextPart = current->next;
            current->next = nullptr;
            current = nextPart;
        }

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
    int n, k;
    cin >> n >> k;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(head, tail, value);
    }

    Solution sol;
    vector<ListNode*> res = sol.splitListToParts(head, k);
    for (auto x : res) {
        printList(x);
        cout << endl;
    }
}