#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int count = 0;
        priority_queue<int> maxHeap(amount.begin(), amount.end());
        while (!maxHeap.empty()) {
            while (maxHeap.top() != 0 && maxHeap.size() >= 2) {
                int a = maxHeap.top();
                maxHeap.pop();
                int b = maxHeap.top();
                maxHeap.pop();

                if (b == 0) {
                    maxHeap.push(a);
                    break;
                }
                count++;
                maxHeap.push(--a);
                maxHeap.push(--b);
            }
            
            if (maxHeap.top() != 0 && maxHeap.size() == 1) {
                count += maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.top() == 0) return count;
        }
        return count;
    }
};
  
int main() {
    vector<int> v ={5, 0, 0};
    Solution sol;
    cout << sol.fillCups(v);
}