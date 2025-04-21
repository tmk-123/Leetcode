#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        unordered_map<int, int> m1, m2;
        for (int i = 0; i < nums.size(); i+=2) {
            m1[nums[i]]++;
        }
        for (int i = 1; i < nums.size(); i+=2) {
            m2[nums[i]]++;
        }

        int max1a = 0, max1b = 0, max2a = 0, max2b = 0;
        int a = 0, b = 0;
        for (auto& [n, freq] : m1) {
            if (freq > max1a) {
                max1b = max1a;
                max1a = freq;
                a = n;
            }
            else if (freq > max1b) {
                max1b = freq;
            }
        }
        for (auto& [n, freq] : m2) {
            if (freq > max2a) {
                max2b = max2a;
                max2a = freq;
                b = n;
            }
            else if (freq > max2b) {
                max2b = freq;
            }
        }

        if (a != b) return nums.size() - max1a - max2a;
        return min(nums.size() - max1a - max2b, nums.size() - max2a - max1b);
    }
};