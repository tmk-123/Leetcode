#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cnt = 0;

    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums, target, 0);
        return cnt;
    }

    void backtrack(vector<int>& nums, int target, int index) {
        if (index == nums.size()) {
            if (target != 0) return;
            cnt++;
            return;
        }
        backtrack(nums, target - nums[index], index + 1);
        backtrack(nums, target + nums[index], index + 1); 
        return;
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
    cout << sol.findTargetSumWays(nums, target);
}