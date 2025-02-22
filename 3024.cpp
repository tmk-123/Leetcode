#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if (nums[1] == nums[2] && nums[2] == nums[0]) return "equilateral";

        sort(nums.begin(), nums.end());
        if (nums[2] - nums[1] >= nums[0] || nums[1] + nums[0] <= nums[2]) return "none";
        if (nums[1] != nums[0] && nums[1] != nums[2] && nums[0] != nums[2]) return "scalene";
        return "isosceles";
    }
};