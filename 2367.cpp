#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> s(nums.begin(), nums.end());
        int count = 0;
        
        for (int num : nums) {
            if (s.count(num + diff) && s.count(num + 2 * diff)) {
                count++;
            }
        }
        
        return count;
    }
};