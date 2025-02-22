#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < temp.size(); i++) {
            if (mp.find(temp[i]) == mp.end()) {
                mp[temp[i]] = i;
            }
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(mp[nums[i]]);
        }
        return res;
    }
};