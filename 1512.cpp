#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
        }

        int cnt = 0;
        for (auto [n, freq] : m) {
            cnt += freq * (freq - 1) / 2;
        }
        return cnt;
    }
};