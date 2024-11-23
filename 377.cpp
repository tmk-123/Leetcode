#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};
int main() {
    int target;
    cin >> target;
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.combinationSum4(nums, target);
}