#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n, 0);

        dp[0] = nums[0], dp[1] = nums[1];

        for (int i = 2; i < n; i++) {
            for (int j = 0; j <= i - 2; j++) {
                dp[i] = max(dp[j] + nums[i], dp[i]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);

    Solution sol;
    cout << sol.rob(nums);
}