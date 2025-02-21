#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3) return -1;
        return nums[1];
    }
};
