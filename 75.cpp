#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int one = 0, zero = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zero++;
            else if (nums[i] == 1) one++;
        }
        int i = 0;
        while (zero--) nums[i++] = 0;
        while (one--) nums[i++] = 1;
        while (i < n) nums[i++] = 2;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    sol.sortColors(nums);
}