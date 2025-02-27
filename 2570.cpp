#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> m;
        
        for (auto& v : nums1) m[v[0]] += v[1];
        for (auto& v : nums2) m[v[0]] += v[1];

        vector<vector<int>> res;
        for (auto& [key, value] : m) {
            res.push_back({key, value});
        }
        return res;
    }
};
