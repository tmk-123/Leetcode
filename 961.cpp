#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
            if (m[n] == nums.size() / 2) return n;
        }
        return 0;
    }
};