#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = n - 2;

        while (index >= 0 && nums[index] >= nums[index + 1]) {
            index--;
        }

        if (index < 0) {
            sort(nums.begin(), nums.end());
        }
        else {
            int i = index + 1;
            for (int j = i; j < n; j++) {
                if (nums[j] > nums[index]) i = j;
            }
            swap(nums[i], nums[index]);

            int l = index + 1, r = n - 1;
            while (l < r) {
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    sol.nextPermutation(nums);

    for (auto x : nums) {
        cout << x << " ";
    }
}