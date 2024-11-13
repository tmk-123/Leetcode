#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxSequence = 0;
        int len = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] + 1) {
                len++;
            }
            else if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            else {
                len = 1;
            }

            maxSequence = max(maxSequence, len);
        }

        return maxSequence;
    }
};

int main() {
    int n;
    vector<int> nums;
    while (cin >> n) {
        nums.push_back(n);
    }

    Solution sol;
    cout << sol.longestConsecutive(nums);
}