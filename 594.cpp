#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxLen = 0;
        int l = 0, r = 0;

        while (r < nums.size()) {
            if (nums[r] - nums[l] == 1) {
                maxLen = max(maxLen, r - l + 1);
                r++;
            }
            else if (nums[r] - nums[l] == 0) r++;
            else l++;
        }
        
        return maxLen;
    }
};

int main() {
    vector<int> v = {1, 3, 2, 2, 5, 2, 3, 7};
    Solution sol;
    cout << sol.findLHS(v);
}