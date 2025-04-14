#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        set<int> st;
        int maxNeg = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) st.insert(nums[i]);
            else maxNeg = max(maxNeg, nums[i]);
        }

        for (auto& val : st) {
            sum += val;
        }

        if (st.size()) return sum;
        return maxNeg;
    }
};