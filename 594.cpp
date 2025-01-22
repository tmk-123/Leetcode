#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] - nums[i] == 1) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};

int main() {
    vector<int> v = {1, 3, 2, 2, 5, 2, 3, 7};
    Solution sol;
    cout << sol.findLHS(v);
}