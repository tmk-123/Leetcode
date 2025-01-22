#include<bits/stdc++.h>

using namespace std;

long lcm(long a, long b) {
    return a * (b / gcd(a, b));
}

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            long currGCD = nums[i];
            long currLCM = nums[i];
            long currProd = nums[i];
            long maxLcm = 10000000000;

            for (int j = i; j < n; j++) {
                if (j > i) {
                    currGCD = gcd(currGCD, nums[j]);
                    currLCM = lcm(currLCM, nums[j]);
                    currProd *= nums[j];
                }
                if (currProd > maxLcm) break;
                if (currProd == currGCD * currLCM) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        } 
        
        return maxLen;
    }
};
int main() {
    vector<int> v = {1,2,1,2,1,1,1};
    Solution sol;
    cout << sol.maxLength(v);
}