#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int> ());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sumSub = 0;
        vector<int> res;
        
        for (int i = 0; i < nums.size(); i++) {
            if (sumSub <= sum - sumSub) {
                res.push_back(nums[i]);
                sumSub += nums[i];
            }
            if (sumSub > sum - sumSub) {
                return res;
            }
        }

        return nums;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    Solution sol;
    vector<int> res = sol.minSubsequence(nums);
    for (int x : res) {
        cout << x << " ";
    }
}