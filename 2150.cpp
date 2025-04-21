#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int& n : nums) m[n]++;

        vector<int> res;
        for (int& n : nums) {
            if (m[n] == 1 && m[n - 1] == 0 && m[n + 1] == 0) res.emplace_back(n);
        }

        return res;
    }
};