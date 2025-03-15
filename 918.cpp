#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxSum = nums[0], minSum = nums[0];
        int curMax = 0, curMin = 0;

        for (int& num : nums) {
            totalSum += num;

            curMax = max(num, curMax + num);
            maxSum = max(curMax, maxSum);

            curMin = min(num, curMin + num);
            minSum = min(curMin, minSum);
        }

        // nếu tất cả số đều âm, totalSum - minSum = 0
        if (maxSum > 0) return max(maxSum, totalSum - minSum);
        return maxSum;
    }
};