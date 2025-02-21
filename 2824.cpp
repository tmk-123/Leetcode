#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int j = nums.size() - 1;
            while (j > i && target - nums[i] <= nums[j]) {
                j--;
            }
            cnt += j - i;
        }
        return cnt;
    }
};
