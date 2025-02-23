#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key) m[nums[i + 1]]++;
        }

        int maxCount = INT_MIN;
        int target = -1;
        for (auto x : m) {
            if (x.second > maxCount) {  
                maxCount = x.second;
                target = x.first;
            }
        }

        return target;
    }
};
