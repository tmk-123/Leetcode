#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxXor = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                int x = nums[i], y = nums[j];
                if (abs(x - y) <= min(x, y)) {
                    maxXor = max(maxXor, x ^ y);
                }
            }
        }
        return maxXor;
    }
};