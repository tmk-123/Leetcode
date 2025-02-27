#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);
        
        unordered_set<int> prefix, suffix;
        vector<int> suffix_count(n + 1, 0);

        // Tính số lượng phần tử khác nhau trong suffix
        for (int i = n - 1; i >= 0; i--) {
            suffix.insert(nums[i]);
            suffix_count[i] = suffix.size();
        }

        // Tính diff[i]
        for (int i = 0; i < n; i++) {
            prefix.insert(nums[i]);
            diff[i] = prefix.size() - suffix_count[i + 1];
        }

        return diff;
    }
};