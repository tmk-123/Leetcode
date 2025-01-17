#include<bits/stdc++.h>

using namespace std;

struct Element {
    int value, index;

    bool operator>(Element other) {
        return value > other.value; // sap xep giam dan, greater se dao nguoc thanh tang dan
    }
}
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
        while (k--) {
            
        }
    }
};
  
int main() {
    vector<int> v = {2, 1, 3, 5, 6};
    Solution sol;
    vector<int> res = sol.getFinalState(v, 5, 2);
}