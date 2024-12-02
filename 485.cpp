#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0, len = 0;

        for (int x : nums) {
            if (x == 1) {
                len++;
                maxLen = max(len, maxLen);
            }
            else {
                len = 0;
            }
        }

        return maxLen;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }
    Solution sol;
    cout << sol.findMaxConsecutiveOnes(nums);
}