#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        int maxSize = 1, maxIndex = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;            
                    prev[i] = j;
                }
            }

            if (maxSize < dp[i]) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }        

        vector<int> res;
        // push maxIndex sau đó mới push prev[i]
        for (int i = maxIndex; i != -1; i = prev[i]) {
            res.push_back(nums[i]);
        }

        return res;
    }
};
int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    vector<int> res = sol.largestDivisibleSubset(nums);
    for (auto x : res) {
        cout << x << " ";
    }
}