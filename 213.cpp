#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return max({nums[0], nums[1], nums[2]});

        vector<int> dp(n, 0);
        vector<int> v(n, 0);
        dp[0] = nums[0], dp[1] = nums[1];
        v[0] = nums[0], v[1] = nums[1], v[2] = nums[2];
        int res = -100;

        for (int i = 2; i < n - 1; i++) {
            for (int j = 0; j <= i - 2; j++) {
                dp[i] = max(dp[j] + nums[i], dp[i]);
                res = max(dp[i], res);
            }
        }

        for (int i = 3; i < n; i++) {
            for (int j = 1; j <= i - 2; j++) {
                v[i] = max(v[i], v[j] + nums[i]);
                res = max(v[i], res);
            }
        }

        return res;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) nums.push_back(n);

    Solution sol;
    cout << sol.rob(nums);
}