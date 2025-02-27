#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, first, last;
        int degree = 0, minLength = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            freq[n]++;
            if (first.find(n) == first.end()) first[n] = i;
            last[n] = i;
            degree = max(degree, freq[n]);
        }

        for (auto& [num, count] : freq) {
            if (count == degree) minLength = min(minLength, last[num] - first[num] + 1);
        }
        return minLength;
    }
};