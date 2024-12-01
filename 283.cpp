#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int cnt = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[left++] = nums[i];
                cnt++;
            }
        }

        for (int i = cnt; i < n; i++) nums[i] = 0; 
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    Solution sol;
    sol.moveZeroes(nums);
}