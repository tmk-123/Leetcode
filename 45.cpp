#include<bits/stdc++.h>

using namespace std;

// Greedy

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int jumps = 0; // số bước nhảy
        int current_end = 0; // đánh dấu vị trí kết thúc của bước nhảy hiện tại
        int farthest = 0; // cập nhập vị trí xa nhất

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            // đi hết current_end để cập nhập vị trí xa nhất, tăng bước nhảy
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                if (current_end >= n - 1) break;
            }
        }

        return jumps;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.jump(nums);
}