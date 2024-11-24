#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = k;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                nums[i] *= -1;
                cnt--;
                if (cnt == 0) return accumulate(nums.begin(), nums.end(), 0);
            }
        }

        sort(nums.begin(), nums.end());
        if (cnt % 2 == 0) return accumulate(nums.begin(), nums.end(), 0);
        else return accumulate(nums.begin(), nums.end(), 0) - 2 * nums[0];
    }
};

int main() {
    int k;
    cin >> k;
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    } 

    Solution sol;
    cout << sol.largestSumAfterKNegations(nums, k);
}