#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }

        vector<int> v;
        for (auto [n, freq] : m) {
            if (freq > 1) v.push_back(n); 
        }
        return v;
    }
};