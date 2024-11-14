#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0];
        int min_product = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(max_product, min_product);

            max_product = max(nums[i], max_product * nums[i]);
            min_product = min(nums[i], min_product * nums[i]);
            result = max(max_product, result);
        }

        return result;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.maxProduct(nums);
}