#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool increasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
    bool decreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) return false;
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        return increasing(nums) || decreasing(nums);
    }
};  