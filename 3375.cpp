#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minVal = INT_MAX;
        unordered_set<int> Set;
        for (int i = 0; i < nums.size(); i++) {
            minVal = min(minVal, nums[i]);
            Set.insert(nums[i]);
        }

        if (minVal < k) return -1;
        if (minVal == k) return Set.size() - 1;
        return Set.size();
    }
};