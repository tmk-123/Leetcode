#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = INT_MIN;
        unordered_map<int, int> m;
        for (int n : nums) {
            m[n]++;
            maxFreq = max(maxFreq, m[n]);
        }

        int cnt = 0;
        for (auto [num, freq] : m) {
            if (freq == maxFreq) cnt+= freq;
        }
        return cnt;
    }
};