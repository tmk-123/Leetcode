#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0 && nums[i] <= threshold) {
                maxLen = max(1, maxLen);
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] > threshold) break;

                    if ((nums[j] % 2) != (nums[j - 1] % 2)) {
                        maxLen = max(maxLen, j - i + 1);
                    }
                    else break;
                }
            }
        }

        return maxLen;
    }
};

int main() {
    vector<int> v = {4, 10, 3};
    Solution sol;
    cout << sol.longestAlternatingSubarray(v, 10);
}