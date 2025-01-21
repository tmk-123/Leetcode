#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minSum = INT_MAX;
        bool found = false;
        int n = nums.size();

        for (int start = 0; start < n; start++) {
            int sum = 0;
            for (int end = start; end < n; end++) {
                sum += nums[end];
                int len = end - start + 1;
                if (len >= l && len <= r && sum > 0) {
                    minSum = min(minSum, sum);
                    found = true;
                }
            }
        }

        return found ? minSum : -1;
    }
};

int main() {
    vector<int> v = {3, -2, 1, 4};
    Solution sol;
    cout << sol.minimumSumSubarray(v, 2, 3);
}