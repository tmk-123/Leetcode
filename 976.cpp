#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 3; i >= 0; i--) {
            if (nums[i + 2] < nums[i + 1] + nums[i]) {
                return nums[i + 2] + nums[i + 1] + nums[i];
            }
        }

        return 0;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.largestPerimeter(nums);
}