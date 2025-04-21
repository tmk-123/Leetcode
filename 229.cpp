#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = floor(nums.size() / 3.0);
        unordered_map<int, int> m;
        for (int& num : nums) {
            m[num]++;
        } 

        vector<int> res;
        for (auto& [num, freq] : m) {
            if (freq > n) res.push_back(num);  
        }
        return res;
    }
};