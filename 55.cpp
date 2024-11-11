#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int current_end = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            farthest = max(farthest, i + nums[i]);

            if (farthest >= nums.size() - 1) return true;
            
            if (current_end == i) {
                if (current_end == farthest) return false;
                current_end = farthest;
            }
        }

        return true;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.canJump(nums);
}