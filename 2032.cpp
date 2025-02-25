#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, int> mask;
        for (int n : nums1) {
            mask[n] |= (1 << 0);
        }
        for (int n : nums2) {
            mask[n] |= (1 << 1);
        }
        for (int n : nums3) {
            mask[n] |= (1 << 2);
        }

        vector<int> res;
        for (auto [n, bitmask] : mask) {
            int temp = n;
            int count = 0;
            while (temp) {
                count += (temp & 1);
                temp = temp >> 1;
            }
            
            if (count >= 2) res.push_back(n);
        }
        return res;
    }
};