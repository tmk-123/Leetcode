#include<bits/stdc++.h>

using namespace std;

struct Element {
    int value, index;

    // phải có const ở tham số và ngoài để hàm cố định, tham số cố định
    bool operator>(const Element& other) const {
        if (value == other.value) return index > other.index;
        return value > other.value; // sap xep giam dan, greater se dao nguoc thanh tang dan
    }
};
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<Element, vector<Element>, greater<Element>> minHeap;
        for (int i = 0; i < nums.size(); i++) minHeap.push({nums[i], i});

        while (k--) {
            Element minElement = minHeap.top();
            minHeap.pop();

            nums[minElement.index] *= multiplier;

            minHeap.push({nums[minElement.index], minElement.index});
        }

        return nums;
    }
};
  
int main() {
    vector<int> v = {1, 3, 5};
    Solution sol;
    vector<int> res = sol.getFinalState(v, 5, 3);
    for (int x : res) {
        cout << x << " ";
    }
}