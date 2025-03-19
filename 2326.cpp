#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode* curr = head;

        while (curr) {
            for (int i = left; i <= right && curr; i++) {
                matrix[top][i] = curr->val;
                curr = curr->next;
            }
            top++;

            for (int i = top; i <= bottom && curr; i++) {
                matrix[i][right] = curr->val;
                curr = curr->next;
            } 
            right--;

            for (int i = right; i >= left && curr; i--) {
                matrix[bottom][i] = curr->val;
                curr = curr->next;
            }
            bottom--;

            for (int i = bottom; i >= top && curr; i--) {
                matrix[i][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }

        return matrix;
    }
};