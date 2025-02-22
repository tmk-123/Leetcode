#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            cnt += mp[nums[i] - k];
        }

        return cnt;
    }
};  