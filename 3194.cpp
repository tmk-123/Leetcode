#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        double minAverage = 1e9;
        while (i < j) {
            minAverage = min(minAverage, (nums[j--] + nums[i++]) / 2.0);
        }
        return minAverage;
    }
};